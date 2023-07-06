#lang rosette
(require data/bit-vector)   ; bitvectors
(require "tdx_lib.rkt")     ; various state defintions and helper functions

;********************* Tables *********************
; (S)EPT -> maps GPA to HPA and page state (shared bit, EPT entry state)
(define secure_EPT (make-hash))
(define-struct secure_EPT_entry (host_physical_address GPA_SHARED state))
(define/contract secure_EPT-contract
    (hash/c integer? secure_EPT_entry? #:flat? #t)
    secure_EPT)

; KET[HKID] -> TD's ephemeral encryption key
(define KET (make-hash))
(define/contract KET-contract
    (hash/c integer? bitvector? #:flat? #t)
    KET)

; KOT[HKID] -> State (free, assigned, reclaimed, flushed, n/a (hkid free), reserved)
; See table 4.3 in TDX specification for state table, table 4.1 for KET and KOT
(define KOT (make-hash))
(define/contract KOT-contract
    (hash/c integer? integer? #:flat? #t)
    KOT)

; TDR
; See table 23.3 on p.171
(define-struct TDR (INIT FATAL NUM_TDCX TDCX_PA CHLDCNT LIFECYCLE_STATE HKID PKG_CONFIG_BITMAP FINALIZED))

; PAMT (p67-68)
; Note that the OWNER field is a bit field from the pa of the TDR, here it
; could probably be some TD_ID instead
; EPOCH is only intended for pages of type PT_REG or PT_EPT
; PAMTs are more complex than this because there are multiple page sizes but
; I don't think that'll impact confidentiality.
(define PAMT (make-hash))
(define-struct PAMT_entry (PAGE_TYPE OWNER BEPOCH))
(define/contract PAMT-contract
    (hash/c integer? PAMT_entry? #:flat? #t)
    PAMT)

; Need some way to model what is in the cache at any given time so that we can model
; flushing the cache during context switches or TD teardown. So I think a map of like
; physical addresses to a cache line structure, where the data field doesn't matter but
; we need to have the TD owner bit and HKID at the very least. Maybe the MAC too

; So on p120 it specifies the components for Ci mode, as the data, a tweaked pa, the TD owner bit, and the MAC key
(define cache (make-hash))
(define-struct cache_entry (TD_OWNER HKID MAC DATA))
(define/contract cache-contract
    (hash/c integer? cache_entry? #:flat? #t)
    cache)

(define TDVPS (make-TDR #f #f 0 0 0 0 0 0 #f))


;********************* Interrupts/Exceptions *********************

; Not certain when it is determined to flush the cache, need to look through the implementation
; for it on transitions from TDX to VMM (exiting SEAM) and TD exiting to TDX
; p.59

(define (flush_cache target_HKID)
    (define keys (hash-keys cache))
    (for ([i keys])
        (define cache_line (hash-ref cache i))
        (when (equal? (cache_entry-HKID cache_line) target_HKID)
            (hash-remove! cache i)
            )
        )
    )

; p.37 - table 3.11
; p.88 - fig 12.2
; It defines that the exit just means that the logical processor's state
; as per p23: cpu state is saved to CVPUCS, synthetic state is loaded, p.37

; TODO: For now using exit_reason to denote interrupt or exception but this will change later
(define (async_td_exit curr_tdr exit_reason)
    (set! TDVPS curr_tdr)   ; save current lp state in TDVPS
    ; probably some context switching abstraction
    )

(define (interrupt curr_tdr)
    (async_td_exit curr_tdr 'interrupt)
    )

(define (exception curr_tdr)
    (async_td_exit curr_tdr 'exception)
    )

;********************* ABI *********************
; TDH_MNG_CREATE - 240

; Returns new TDR on success, on failure returns false
; Assuming that CREATE updates the page state in the PAMT to PT_TDR as the specification states:
;   "Initialize the TDR page metadata in PAMT."
(define (TDH_MNG_CREATE pa HKID)
    (define hkid_state (hash-ref KOT HKID #f))
    (define page_state (hash-ref PAMT pa #f))
    (when (and (is_hkid_private HKID) 
        (or (equal? hkid_state #f) (equal? hkid_state HKID_FREE)) 
        (or (equal? page_state #f) (equal? page_state PT_NDA)))
        (begin
            (hash-set! KOT HKID HKID_ASSIGNED)
            (hash-set! PAMT pa (make-PAMT_entry PT_TDR 0 0)) ; TODO: owner identifier
            (make-TDR #f #f 0 0 0 TD_HKID_ASSIGNED HKID 0 #f))
        )
    )

; TDH_MNG_KEY_CONFIG - 244
; On success returns the new TDR, on failure returns false
(define (TDH_MNG_KEY_CONFIG pa tdr)
    (define page_entry (hash-ref PAMT pa #f))
    (define page_state 
        (if (PAMT_entry? page_entry)
            (PAMT_entry-PAGE_TYPE page_entry)
            #f))
    (define td_fatal (TDR-FATAL tdr))
    (define hkid_state (TDR-LIFECYCLE_STATE tdr))
    (when (and (equal? page_state PT_TDR) (not td_fatal))
        (begin
            ; mutate the KET entry for the TDR's HKID to have a symbolic ephemeral key
            (hash-set! KET (TDR-HKID tdr) key_val)  ; TODO: key_val
            ; make updated TDR structure to return
            (struct-copy TDR tdr
                            [LIFECYCLE_STATE TD_KEYS_CONFIGURED]))
        )
    )

; TDH_MNG_VPFLUSHDONE - 251
; based on flushdone but as we are abstracting the packages this also flushes the cache
; Returns updated tdr on success, false on failure
(define (TDH_MNG_VPFLUSH pa tdr)
    (define page_entry (hash-ref PAMT pa #f))
    (define page_state 
        (if (PAMT_entry? page_entry)
            (PAMT_entry-PAGE_TYPE page_entry)
            #f))
    (define td_state (TDR-LIFECYCLE_STATE tdr))
    (define hkid_state (hash-ref KOT (TDR-HKID tdr)))
    (if (and (equal? page_state PT_TDR) 
             (or (equal? td_state TD_HKID_ASSIGNED) (equal? TD_KEYS_CONFIGURED))
             (equal? hkid_state HKID_ASSIGNED))
            (begin
                (flush_cache (TDR-HKID tdr))
                (hash-set! KOT (TDR-HKID tdr) HKID_FLUSHED)
                (struct-copy TDR tdr
                    [LIFECYCLE_STATE TD_BLOCKED]))
            #f)
    )



; TDH_MNG_KEY_FREEID - 246
(define (TDH_MNG_KEY_FREEID pa tdr)
    (define page_entry (hash-ref PAMT pa #f))
    (define page_state 
        (if (PAMT_entry? page_entry)
            (PAMT_entry-PAGE_TYPE page_entry)
            #f))
    (define hkid_state (TDR-LIFECYCLE_STATE tdr))
    (define hkid (TDR-HKID tdr))
    (define kot_entry (hash-ref KOT hkid #f))

    (when (and (equal? page_state PT_TDR) (equal? hkid_state TD_BLOCKED) (equal? kot_entry HKID_FLUSHED))
        (begin
            (hash-set! KOT hkid HKID_FREE)
            (struct-copy TDR tdr
                            [LIFECYCLE_STATE TD_TEARDOWN]))
        )
    )

; TDH_PHYMEM_PAGE_RECLAIM - 263
; So tdr is either the tdr at pa or the tdr who owns the page at pa
; Either returns the updated tdr if necessary or returns false for no output
(define (TDH_PHYMEM_PAGE_RECLAIM pa tdr)
    (define page_entry (hash-ref PAMT pa #f))
    (define page_state
        (if (PAMT_entry? page_entry)
            (PAMT_entry-PAGE_TYPE page_entry)
            #f))
    
    (if (nor (equal? page_state PT_NDA) (equal? PT_RSVD))
        (begin
            ; Set new page state and update TDR
            
            (if (equal? page_state PT_TDR)
                (begin
                    (define td_state (TDR-LIFECYCLE_STATE tdr))
                    (define chldcnt (TDR-CHLDCNT tdr))
                    (when (and (equal? td_state TD_TEARDOWN) (equal? chldcnt 0))
                        (hash-set! PAMT pa (struct-copy PAMT_entry page_entry
                                                        [PAGE_TYPE PT_NDA])))
                    #f)
                (begin
                    (define td_state (TDR-LIFECYCLE_STATE tdr))
                    (when (equal? td_state TD_TEARDOWN)
                        (begin
                            (hash-set! PAMT pa (struct-copy PAMT_entry page_entry
                                                        [PAGE_TYPE PT_NDA]))
                            (define new_childcount (- (TDR-CHLDCNT tdr) 1))
                            (struct-copy TDR tdr
                                [CHLDCNT new_childcount]))))))
        #f))

; TDH_MNG_INIT - 242
; Generally configures TD control structures not necessary for demonstrating confidentiality
(define (TDH_MNG_INIT pa tdr)
    (define page_entry (hash-ref PAMT pa #f))
    (define page_state 
        (if (PAMT_entry? page_entry)
            (PAMT_entry-PAGE_TYPE page_entry)
            #f))
    (define fatal (TDR-FATAL tdr))
    (define init (TDR-INIT tdr))
    (define lifecycle_state (TDR-LIFECYCLE_STATE tdr))
    
    (when (and (equal? page_state PT_TDR) (not fatal) (not init) (equal? lifecycle_state TD_KEYS_CONFIGURED))
        (begin
            (struct-copy TDR tdr
                            [INIT #t]))
        )
    )

; TDH_MNG_FINALIZE - 257
(define (TDH_MNG_FINALIZE pa tdr)
    (define page_entry (hash-ref PAMT pa #f))
    (define page_state
        (if (PAMT_entry? page_entry)
            (PAMT_entry-PAGE_TYPE page_entry)
            #f))
    (define fatal (TDR-FATAL tdr))
    (define tdr_state (TDR-LIFECYCLE_STATE tdr))
    (define init (TDR-INIT tdr))
    (define finalized (TDR-FINALIZED tdr))

    (if (and (equal? page_state PT_TDR) 
             (not fatal) 
             (equal? tdr_state TD_KEYS_CONFIGURED)
             (init)
             (not finalized))
            (struct-copy TDR tdr
                            [FINALIZED #t])
            #f))


; Example TD creation and key resource assignment sequence
(define temp_tdr (TDH_MNG_CREATE 0 5))
(displayln (TDR-LIFECYCLE_STATE temp_tdr))
(displayln PAMT)

(define pamt_entry (hash-ref PAMT 0))
(displayln (PAMT_entry-PAGE_TYPE pamt_entry))
(displayln (TDR-LIFECYCLE_STATE temp_tdr))

(set! temp_tdr (TDH_MNG_KEY_CONFIG 0 temp_tdr))
(displayln KET)
(displayln (PAMT_entry-PAGE_TYPE pamt_entry))
(displayln (TDR-LIFECYCLE_STATE temp_tdr))

; Cache testing
(hash-set! cache 1 (make-cache_entry 0 0 0 0))
(hash-set! cache 2 (make-cache_entry 0 0 0 0))
(hash-set! cache 3 (make-cache_entry 0 1 0 0))
(flush_cache 0)
(displayln cache)
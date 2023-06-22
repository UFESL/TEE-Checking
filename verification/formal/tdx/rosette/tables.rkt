#lang rosette
(require data/bit-vector)
(require "tdx_lib.rkt")

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
(define-struct TDR (INIT FATAL NUM_TDCX TDCX_PA CHLDCNT LIFECYCLE_STATE HKID PKG_CONFIG_BITMAP))

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


;********************* Interrupts/Exceptions *********************
; Need to model how each modifies the KET, KOT, TDR, and SEPT

; Specifically, an interrupt or exception can cause a TD exit so I need to model
; what happens to the KET KOT TDR and SEPT


;********************* ABI *********************
; TDH_MNG_CREATE - 240

; Returns new TDR on success, on failure returns false
; Assuming that CREATE updates the page state in the PAMT to PT_TDR as the specification states:
;   "Initialize the TDR page metadata in PAMT."
(define (TDH_MNG_CREATE pa HKID)
    (define hkid_state (hash-ref KOT HKID #f))
    (define page_state (hash-ref PAMT pa #f))
    (if (and (is_hkid_private HKID) 
        (or (equal? hkid_state #f) (equal? hkid_state HKID_FREE)) 
        (or (equal? page_state #f) (equal? page_state PT_NDA)))
        (begin
            (hash-set! KOT HKID HKID_ASSIGNED)
            (hash-set! PAMT pa (make-PAMT_entry PT_TDR 0 0)) ; TODO: owner identifier
            (make-TDR 0 0 0 0 0 TD_HKID_ASSIGNED HKID 0))
        #f)
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
    (if (and (equal? page_state PT_TDR) (equal? td_fatal 0))
        (begin
            ; mutate the KET entry for the TDR's HKID to have a symbolic ephemeral key
            (hash-set! KET (TDR-HKID tdr) key_val)  ; TODO: key_val
            ; make updated TDR structure to return
            (struct-copy TDR tdr
                            [LIFECYCLE_STATE TD_KEYS_CONFIGURED]))
        #f)
    )


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

; TDH_MNG_VPFLUSH
; TDH_MNG_KEY_FREEID
; TDH_PHYMEM_PAGE_RECLAIM
; TDH_MNG_INIT
; TDH_MNG_FINALIZE
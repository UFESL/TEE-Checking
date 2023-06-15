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
; TDR is root control struct of guest TD, contains minimal set of state params 
; to enable guest control even duringtimes when TD's private HKID is not known,
; or when TD key managemnet state does not permit access to 
(define-struct TDR (key_state HKID key))
(define dummy_TDR (make-TDR NA (make-bit-vector MK_TME_KEYID_BITS #f) 
    (make-bit-vector EPHEMERAL_KEY_LENGTH #f)))

;********************* Tests/Examples *********************

; (random-seed 1)

; HKID_gen example
(displayln "Generate a private key:")
(displayln (HKID_gen #t))
(displayln "Generate a public key:")
(displayln (HKID_gen #f))

; Example of adding a mapping to KET using HKID_gen to get a random private HKID
(define temp (HKID_gen #t))
(hash-set! KET temp (make-bit-vector EPHEMERAL_KEY_LENGTH #f))
(displayln KET)
(displayln (bit-vector->string (hash-ref KET temp)))

; Mapping HKID to HKID state KOT example
(hash-set! KOT temp HKID_FREE)
(displayln KOT)



(define temp1 (make-hash))
(define/contract temp-contract
    (hash/c integer? boolean? #:flat? #t)
    temp1)

(hash-set! temp1 1 #f)
(hash-set! temp1 guest_physical_address #f)

(displayln temp1)
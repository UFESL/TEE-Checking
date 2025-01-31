#lang rosette

;; Guest Context Table: Maps guest handles to their state and encryption properties
(define GCTX (make-hash))

(define/contract GCTX-contract
  (hash/c integer? (list/c symbol? integer? integer? integer? integer? integer? integer? integer?))
  GCTX)

;; Add a new guest entry to the GCTX table
(define (add-guest handle state asid policy vek tek tik nonce ms)
  (hash-set! GCTX handle (list state asid policy vek tek tik nonce ms)))

;; Retrieve a guest entry from GCTX
(define (get-guest handle)
  (hash-ref GCTX handle #f))

;; Update guest state in GCTX
(define (update-guest-state handle new-state)
  (when (hash-has-key? GCTX handle)
    (define guest (hash-ref GCTX handle))
    (hash-set! GCTX handle (list new-state (cadr guest) (caddr guest) (cadddr guest)
                                 (list-ref guest 4) (list-ref guest 5) (list-ref guest 6)
                                 (list-ref guest 7) (list-ref guest 8)))))



;; ASID Table: Maps ASIDs to guest handles
(define ASIDT (make-hash))

(define/contract ASIDT-contract
  (hash/c integer? integer?)
  ASIDT)

;; Allocate an ASID to a guest
(define (SEV_ASID_ALLOC handle asid)
  (when (not (hash-has-key? ASIDT asid))
    (hash-set! ASIDT asid handle)))

;; Free an ASID
(define (SEV_ASID_FREE asid)
  (when (hash-has-key? ASIDT asid)
    (hash-remove! ASIDT asid)))

;; Retrieve the owner of an ASID
(define (get-asid-owner asid)
  (hash-ref ASIDT asid #f))



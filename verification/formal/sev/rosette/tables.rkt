#lang rosette

#|
Guest Context Table 
Maps guest handles to their state and encryption properties
|#

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


;; Page Encryption Table: Maps physical addresses to encryption status
(define PEB (make-hash))

(define/contract PEB-contract
  (hash/c integer? symbol?)
  PEB)

;; Mark a page as encrypted
(define (SEV_ENCRYPT_PAGE phys_addr)
  (hash-set! PEB phys_addr 'ENCRYPTED))

;; Mark a page as decrypted
(define (SEV_DECRYPT_PAGE phys_addr)
  (hash-set! PEB phys_addr 'DECRYPTED))

;; Check if a page is encrypted
(define (is-page-encrypted? phys_addr)
  (equal? (hash-ref PEB phys_addr 'UNKNOWN) 'ENCRYPTED))


;; Guest Policy Table: Stores security policies for each guest
(define GuestPolicy (make-hash))

(define/contract GuestPolicy-contract
  (hash/c integer? (list/c boolean? boolean? boolean? boolean? boolean? boolean?))
  GuestPolicy)

;; Set policy restrictions for a guest
(define (set-guest-policy handle nodbg noks es nosend domain sev)
  (hash-set! GuestPolicy handle (list nodbg noks es nosend domain sev)))

;; Retrieve a guest's policy
(define (get-guest-policy handle)
  (hash-ref GuestPolicy handle #f))

;; Check if debugging is allowed for a guest
(define (is-debugging-allowed? handle)
  (not (car (hash-ref GuestPolicy handle '(#t #t #t #t #t #t)))))

;; Check if migration is allowed for a guest
(define (is-migration-allowed? handle)
  (not (list-ref (hash-ref GuestPolicy handle '(#t #t #t #t #t #t)) 3)))


;; Guest State Machine: Tracks state transitions of each guest
(define GSTATE (make-hash))

(define/contract GSTATE-contract
  (hash/c integer? symbol?)
  GSTATE)

;; Set the state of a guest
(define (set-guest-state handle new-state)
  (hash-set! GSTATE handle new-state))

;; Retrieve the state of a guest
(define (get-guest-state handle)
  (hash-ref GSTATE handle 'UNINIT))

;; Transition guest state based on lifecycle events
(define (transition-guest handle event)
  (define current-state (hash-ref GSTATE handle 'UNINIT))
  (match (list current-state event)
    [('UNINIT 'LAUNCH_START) (set-guest-state handle 'LUPDATE)]
    [('LUPDATE 'LAUNCH_UPDATE_DATA) (set-guest-state handle 'LSECRET)]
    [('LSECRET 'LAUNCH_FINISH) (set-guest-state handle 'RUNNING)]
    [('RUNNING 'SEND_START) (set-guest-state handle 'SUPDATE)]
    [('SUPDATE 'SEND_FINISH) (set-guest-state handle 'SENT)]
    [('SENT 'DECOMMISSION) (set-guest-state handle 'UNINIT)]
    [_ (error "Invalid Transition!")]))


;; Memory Encryption Key Table: Maps ASIDs to VEKs (encryption keys)
(define MEKT (make-hash))

(define/contract MEKT-contract
  (hash/c integer? integer?)
  MEKT)

;; Assign a VEK to an ASID
(define (assign-vek asid vek)
  (hash-set! MEKT asid vek))

;; Retrieve a VEK for an ASID
(define (get-vek asid)
  (hash-ref MEKT asid #f))

;; Delete a VEK from the table
(define (delete-vek asid)
  (hash-remove! MEKT asid))
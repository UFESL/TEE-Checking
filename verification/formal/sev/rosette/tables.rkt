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




; TEST CASES

(require rackunit)

;; Test Guest Context Table
(define (test-gctx)
  (add-guest 1 'UNINIT 1001 0 1111 2222 3333 4444 5555)
  
  (check-equal? (get-guest 1) '(UNINIT 1001 0 1111 2222 3333 4444 5555) "Guest should be initialized")

  (update-guest-state 1 'RUNNING)

  (check-equal? (get-guest 1) '(RUNNING 1001 0 1111 2222 3333 4444 5555) "Guest state should be updated to RUNNING"))

(test-gctx)


;; Test ASID Table
(define (test-asidt)
  (SEV_ASID_ALLOC 1 1001)

  (check-equal? (get-asid-owner 1001) 1 "ASID 1001 should be assigned to guest 1")

  (SEV_ASID_FREE 1001)

  (check-false (get-asid-owner 1001) "ASID 1001 should be freed and return #f"))

(test-asidt)


;; Test Page Encryption Table
(define (test-peb)
  (SEV_ENCRYPT_PAGE 0x1000)

  (check-true (is-page-encrypted? 0x1000) "Page 0x1000 should be encrypted")

  (SEV_DECRYPT_PAGE 0x1000)

  (check-false (is-page-encrypted? 0x1000) "Page 0x1000 should be decrypted"))

(test-peb)



;; Test Guest Policy Table
(define (test-guestpolicy)
  (set-guest-policy 1 #t #f #t #f #t #t)  ;; Debugging disabled, Migration allowed

  (check-false (is-debugging-allowed? 1) "Debugging should not be allowed")

  (check-true (is-migration-allowed? 1) "Migration should be allowed"))

(test-guestpolicy)



;; Test Guest State Machine
(define (test-gstate)
  (check-equal? (get-guest-state 1) 'UNINIT "Guest should start in UNINIT state")

  (transition-guest 1 'LAUNCH_START)

  (check-equal? (get-guest-state 1) 'LUPDATE "Guest should transition to LUPDATE")

  (transition-guest 1 'LAUNCH_UPDATE_DATA)

  (check-equal? (get-guest-state 1) 'LSECRET "Guest should transition to LSECRET")

  (transition-guest 1 'LAUNCH_FINISH)

  (check-equal? (get-guest-state 1) 'RUNNING "Guest should transition to RUNNING"))

(test-gstate)



;; Test Memory Encryption Key Table
(define (test-mekt)
  (assign-vek 1001 0xABCD)

  (check-equal? (get-vek 1001) 0xABCD "VEK for ASID 1001 should be 0xABCD")

  (delete-vek 1001)

  (check-false (get-vek 1001) "VEK for ASID 1001 should be deleted"))

(test-mekt)



; ABIS Starts here



;; LAUNCH_START: Initializes a new SEV guest
(define (LAUNCH_START handle asid policy)
  (define current-state (get-guest-state handle))
  (when (equal? current-state 'UNINIT)
    (add-guest handle 'LUPDATE asid policy 0 0 0 0 0) ;; Initialize guest with zeroed encryption keys
    (SEV_ASID_ALLOC handle asid)
    (set-guest-state handle 'LUPDATE)))


;; LAUNCH_UPDATE_DATA: Encrypts guest memory pages
(define (LAUNCH_UPDATE_DATA handle memory-pages)
  (define current-state (get-guest-state handle))
  (when (equal? current-state 'LUPDATE)
    (for-each SEV_ENCRYPT_PAGE memory-pages) ;; Encrypt all pages
    (set-guest-state handle 'LSECRET)))


;; LAUNCH_MEASURE: Computes attestation measurement
(define (LAUNCH_MEASURE handle)
  (define current-state (get-guest-state handle))
  (when (equal? current-state 'LSECRET)
    (define guest (get-guest handle))
    (define measurement (bv 0xDEADBEEF 64)) ;; Placeholder for actual measurement computation
    (hash-set! GCTX handle (append guest (list measurement))) ;; Store measurement
    (set-guest-state handle 'LSECRET))) ;; Remains in LSECRET state


;; LAUNCH_SECRET: Injects encrypted secrets into guest memory
(define (LAUNCH_SECRET handle secrets)
  (define current-state (get-guest-state handle))
  (when (equal? current-state 'LSECRET)
    (define guest (get-guest handle))
    (define encrypted-secrets (bv 0xCAFEBABE 64)) ;; Placeholder for actual encryption
    (hash-set! GCTX handle (append guest (list encrypted-secrets))) ;; Store encrypted secrets
    (set-guest-state handle 'LSECRET))) ;; Remains in LSECRET state


;; LAUNCH_FINISH: Finalizes guest launch
(define (LAUNCH_FINISH handle)
  (define current-state (get-guest-state handle))
  (when (equal? current-state 'LSECRET)
    (set-guest-state handle 'RUNNING)))



;; ACTIVATE: Assigns ASID and loads encryption keys
(define (ACTIVATE handle)
  (define current-state (get-guest-state handle))
  (when (or (equal? current-state 'LUPDATE) (equal? current-state 'LSECRET))
    ;; Generate a new encryption key (symbolic)
    (define vek (bv 128 256))  ;; 256-bit symbolic AES key
    
    ;; Retrieve ASID from guest context
    (define guest (get-guest handle))
    (define asid (cadr guest))  ;; ASID is stored in the second field

    ;; Assign VEK to ASID
    (assign-vek asid vek)
    
    ;; Update Guest Context with VEK
    (hash-set! GCTX handle (append guest (list vek)))
    
    ;; Transition guest state to RUNNING
    (set-guest-state handle 'RUNNING)))



;; DEACTIVATE: Deallocates ASID and clears encryption keys
(define (DEACTIVATE handle)
  (define current-state (get-guest-state handle))
  (when (equal? current-state 'RUNNING)
    ;; Retrieve ASID from guest context
    (define guest (get-guest handle))
    (define asid (cadr guest))  ;; ASID is stored in the second field
    
    ;; Remove encryption key
    (delete-vek asid)
    
    ;; Free ASID
    (SEV_ASID_FREE asid)

    ;; Reset guest context
    (hash-remove! GCTX handle)
    
    ;; Transition guest state to UNINIT
    (set-guest-state handle 'UNINIT)))


;  TEST CASES


(define (test-launch-start)
  (LAUNCH_START 1 1001 0) ;; Handle = 1, ASID = 1001, Policy = 0
  
  (check-equal? (get-guest-state 1) 'LUPDATE "Guest should be in LUPDATE state")
  (check-equal? (get-asid-owner 1001) 1 "ASID 1001 should be assigned to guest 1"))

(test-launch-start)


(define (test-launch-update-data)
  (LAUNCH_UPDATE_DATA 1 '(0x1000 0x2000))
  
  (check-equal? (get-guest-state 1) 'LSECRET "Guest should be in LSECRET state")
  (check-true (is-page-encrypted? 0x1000) "Page 0x1000 should be encrypted")
  (check-true (is-page-encrypted? 0x2000) "Page 0x2000 should be encrypted"))

(test-launch-update-data)


(define (test-launch-measure)
  (LAUNCH_MEASURE 1)

  (define guest (get-guest 1))
  (check-true (not (equal? (list-ref guest 8) #f)) "Measurement should be computed and stored"))

(test-launch-measure)


(define (test-launch-secret)
  (LAUNCH_SECRET 1 '(0xDEADBEEF))

  (define guest (get-guest 1))
  (check-true (not (equal? (list-ref guest 9) #f)) "Secrets should be securely injected"))

(test-launch-secret)


(define (test-launch-finish)
  (LAUNCH_FINISH 1)
  
  (check-equal? (get-guest-state 1) 'RUNNING "Guest should be in RUNNING state"))

(test-launch-finish)


(define (test-activate)
  (ACTIVATE 1)

  (check-equal? (get-guest-state 1) 'RUNNING "Guest should remain in RUNNING state after activation")
  (check-true (not (equal? (get-vek 1001) #f)) "Encryption key should be assigned"))

(test-activate)


(define (test-deactivate)
  (DEACTIVATE 1)

  (check-equal? (get-guest-state 1) 'UNINIT "Guest should be in UNINIT state after deactivation")
  (check-false (get-asid-owner 1001) "ASID 1001 should be freed")
  (check-false (get-vek 1001) "Encryption key should be removed"))

(test-deactivate)

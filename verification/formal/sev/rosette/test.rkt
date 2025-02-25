#lang rosette

(require rackunit)
(require (file "tables.rkt"))
(require (file "abi.rkt"))


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



;  TEST CASES for ABIs


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
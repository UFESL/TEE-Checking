#lang rosette

(require rackunit)
(require (file "abi.rkt"))
(require "tables.rkt")


; TEST CASES for Tables

;; Test Guest Context Table
(define (test-gctx-add)
  (add-guest 1 'UNINIT 1001 0 1111 2222 3333 4444 5555)
  (check-equal? (get-guest 1) '(UNINIT 1001 0 1111 2222 3333 4444 5555 0 #f) "Guest should be initialized"))

(test-gctx-add)


;; Test Guest Context Table
(define (test-gctx-update)
  (update-guest-state 1 'RUNNING)
  (check-equal? (get-guest 1) '(RUNNING 1001 0 1111 2222 3333 4444 5555 0 #f) "Guest state should be updated to RUNNING"))
(test-gctx-update)

;; Test ASID Table
(define (test-asidt)
  (SEV_ASID_ALLOC 1 1001)
  (check-equal? (get-asid-owner 1001) 1 "ASID 1001 should be assigned to guest 1")
  (SEV_ASID_FREE 1001)
  (check-false (get-asid-owner 1001) "ASID 1001 should be freed and return #f"))
(test-asidt)


;; Test Page Encryption Table
(define (test-peb)
  (SEV_ENCRYPT_PAGE #x1000)
  (check-true (is-page-encrypted? #x1000) "Page #x1000 should be encrypted")
  (SEV_DECRYPT_PAGE #x1000)
  (check-false (is-page-encrypted? #x10000) "Page #x1000 should be decrypted"))

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
  (assign-vek 1001 #xABCD)
  (check-equal? (get-vek 1001) #xABCD "VEK for ASID 1001 should be 0xABCD")
  (delete-vek 1001)
  (check-false (get-vek 1001) "VEK for ASID 1001 should be deleted"))

(test-mekt)

;; Test GHCB
(define (test-ghcb)
  (set-ghcb-state! 1 'partial)
  (check-equal? (get-ghcb-state 1) 'partial "GHCB state should be set to partial"))
(test-ghcb)

;; Test VMCB
(define (test-vmcb)
  (save-registers-to-vmcb 1 '(enc-r1 enc-r2))
  (check-equal? (load-registers-from-vmcb 1) '(enc-r1 enc-r2) "Encrypted registers should be loaded"))
(test-vmcb)

;; Test RMP
(define (test-rmp)
  (assign-page-to-guest #x2000 1001)
  (check-true (owns-page? 1001 #x2000) "Guest 1 should own page #x2000")
  (unassign-page #x2000)
  (check-false (owns-page? 1001 #x2000) "Page #x2000 should be unassigned"))
(test-rmp)

;; Test VMPL
(define (test-vmpl)
  (set-vmpl 1001 2)
  (check-equal? (get-vmpl 1001) 2 "VMPL should be set to 2")
  (check-true (has-vmpl-privilege? 1001 3) "Guest should have lower or equal VMPL access")
  (check-false (has-vmpl-privilege? 1001 1) "Guest should not have higher VMPL access"))
(test-vmpl)

;; Test Page Version Table
(define (test-page-version)
  (set-page-version! #x3000 5)
  (check-equal? (get-page-version #x3000) 5 "Page version should be set to 5"))
(test-page-version)

;; Test PVALIDATE Flag
(define (test-pvalidate)
  (mark-page-invalidated! #x4000) ;
  (check-false (is-page-validated? #x4000) "Page should be marked as validated")
  (check-false (is-page-validated? #x4001) "Page #x4001 should not be validated"))
(test-pvalidate)


;  TEST CASES for ABIs
; (handle = 2, ASID = 1002)


(define (test-launch-start)
  (LAUNCH_START 2 1002 0) ;; Handle = 1, ASID = 1001, Policy = 0
  (check-equal? (get-guest-state 2) 'LUPDATE "Guest should be in LUPDATE state")
  (check-equal? (get-asid-owner 1002) 2 "ASID 1001 should be assigned to guest 1"))

(printf "DEBUG: Guest before launch-start: ~a\n" (get-guest 2))
(test-launch-start)
(printf "DEBUG: Guest after launch-start: ~a\n" (get-guest 2))

(define (test-launch-update-data)
  (LAUNCH_UPDATE_DATA 2 '(#x1000 #x2000))
  (check-equal? (get-guest-state 2) 'LSECRET "Guest should be in LSECRET state")
  (check-true (is-page-encrypted? #x1000) "Page 0x1000 should be encrypted")
  (check-true (is-page-encrypted? #x2000) "Page 0x2000 should be encrypted"))

(printf "DEBUG: Guest before update-data: ~a\n" (get-guest 2))
(test-launch-update-data)
(printf "DEBUG: Guest after update-data: ~a\n" (get-guest 2))


(define (test-launch-measure)
  (LAUNCH_MEASURE 2)
  (define guest (get-guest 2))
  (check-true (not (equal? (list-ref guest 10) #f)) "Measurement should be computed and stored"))
  

(printf "DEBUG: Guest before launch-messure: ~a\n" (get-guest 2))
(test-launch-measure)
(printf "DEBUG: Guest after launch-messure: ~a\n" (get-guest 2))


(define (test-launch-secret)
  (LAUNCH_SECRET 2 '(0xDEADBEEF))
  (define guest (get-guest 2))
  (check-true (not (equal? (list-ref guest 10) #f)) "Secrets should be securely injected"))

(printf "DEBUG: Guest before launch-secret: ~a\n" (get-guest 2))
(test-launch-secret)
(printf "DEBUG: Guest after launch-secret: ~a\n" (get-guest 2))


(define (test-launch-finish)
  (LAUNCH_FINISH 2)
  (check-equal? (get-guest-state 2) 'RUNNING "Guest should be in RUNNING state"))

(printf "DEBUG: Guest before launch-finish: ~a\n" (get-guest 2))
(test-launch-finish)
(printf "DEBUG: Guest after launch-finish: ~a\n" (get-guest 2))


(define (test-activate)
  (ACTIVATE 2)
  (check-equal? (get-guest-state 2) 'RUNNING "Guest should remain in RUNNING state after activation")
  (check-true (not (equal? (get-vek 1002) #f)) "Encryption key should be assigned"))

(printf "DEBUG: Guest before activate: ~a\n" (get-guest 2))
(test-activate)
(printf "DEBUG: Guest after activate: ~a\n" (get-guest 2))


(define (test-deactivate)
  (DEACTIVATE 2)
  (check-equal? (get-guest-state 2) 'UNINIT "Guest should be in UNINIT state after deactivation")
  (check-false (get-asid-owner 1002) "ASID 1001 should be freed")
  (check-false (get-vek 1002) "Encryption key should be removed"))

(printf "DEBUG: Guest before deactivate: ~a\n" (get-guest 2))
(test-deactivate)
(printf "DEBUG: Guest after deactivate: ~a\n" (get-guest 2))

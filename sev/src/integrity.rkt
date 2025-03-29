#lang rosette

(require "tables.rkt")
(require "abi.rkt")

;; ---------------------------
;; IP 1: Guest must not skip mandatory launch states
;; Property: Guest should not enter RUNNING state directly from UNINIT without passing required launch states.
;; ---------------------------
(define (check-launch-state-integrity)
  (printf "\n[IP 1] Guest must not skip mandatory launch states\n")
  (printf "Property: Guest should not enter RUNNING state directly from UNINIT without passing required launch states.\n\n")

  (define-symbolic guest-id integer?)

  ;; Add guest in UNINIT state
  (add-guest guest-id 'UNINIT 1001 0 0 0 0 0 0)

  ;; Attempt to transition directly to RUNNING (should fail)
  (define result (solve
                  (assert
                   (begin
                     (transition-guest guest-id 'LAUNCH_FINISH)
                     #t)))) ;; if this executes successfully, it's a violation

  ;; Report outcome
  (if (unsat? result)
      (printf "\n ✅ PASS: Invalid lifecycle transition to RUNNING was blocked.\n\n")
      (begin
        (printf "\n ❌ FAIL: Guest skipped required states before RUNNING!\n")
        (printf "Counterexample: guest-id = ~a\n"
                (evaluate guest-id result)))))


;; ---------------------------
;; IP 2: Guest state transitions must be atomic
;; Property: During a guest’s state transition, no intermediate or undefined state should be visible.
;; ---------------------------
(define (check-atomic-state-transition)
  (printf "\n[IP 2] Guest state transitions must be atomic\n")
  (printf "Property: During a guest’s state transition, no intermediate or undefined state should be visible.\n\n")

  (define-symbolic guest-id integer?)

  ;; Set initial state manually to LUPDATE (after LAUNCH_START)
  (add-guest guest-id 'LUPDATE 1001 0 0 0 0 0 0)
  (set-guest-state guest-id 'LUPDATE)

  ;; Simulate transition to LSECRET (done after LAUNCH_UPDATE_DATA)
  ;; But attacker reads state during transition
  (define observed-state (get-guest-state guest-id)) ;; Attacker observes GSTATE

  ;; Execute transition
  (transition-guest guest-id 'LAUNCH_UPDATE_DATA)

  ;; After transition, guest is in LSECRET
  (define valid-before 'LUPDATE)
  (define valid-after  'LSECRET)

  ;; Violation: observed-state is neither the original nor the final one
  (define violation (and (not (equal? observed-state valid-before))
                         (not (equal? observed-state valid-after))))

  ;; Solve
  (define result (solve (assert violation)))

  (if (unsat? result)
      (printf "\n ✅ PASS: No intermediate state was visible during transition.\n\n")
      (begin
        (printf "\n ❌ FAIL: Guest state was observable in intermediate/undefined state!\n")
        (printf "Counterexample: guest-id = ~a, observed-state = ~a\n"
                (evaluate guest-id result)
                (evaluate observed-state result)))))


;; ---------------------------
;; IP 3: Secrets must not persist through migration
;; Property: Once a guest is migrated, any secrets injected on the source platform
;;           must no longer be present in the destination guest context.
;; ---------------------------

(define (check-secrets-not-migrated)
  (printf "\n[IP 3] Secrets must not persist through migration\n")
  (printf "Property: Secrets injected before migration must not persist on the destination side.\n\n")

  (define-symbolic guest-id integer?)
  (define-symbolic phys-page integer?)

  ;; Setup guest and inject secret
  (add-guest guest-id 'LSECRET 1001 0 0 0 0 0 0)
  (set-guest-state guest-id 'LSECRET)
  (define secret (bv #xCAFEBABE 64))
  (define g-before (get-guest guest-id))
  (hash-set! GCTX guest-id (append g-before (list secret)))

  ;; Simulate guest reaching RUNNING state before migration
  (set-guest-state guest-id 'RUNNING)
  (SEND_START guest-id)

  (SEV_ENCRYPT_PAGE phys-page)
  (SEND_UPDATE_DATA guest-id (list phys-page))

  ;; Simulate migration (on destination platform)
  (set-guest-state guest-id 'RUPDATE)
  (RECEIVE_UPDATE_DATA guest-id (list phys-page))

  ;; Now guest is running again on destination
  (define post-migration (get-guest guest-id))

  ;; Violation: secrets (at index ≥ 10) should not persist
  (define secrets-leaked? (>= (length post-migration) 11))

  (define result (solve (assert secrets-leaked?)))

  (if (unsat? result)
      (printf "\n ✅ PASS: Secrets are cleared during migration.\n\n")
      (begin
        (printf "\n ❌ FAIL: Secrets remain in guest context after migration!\n")
        (printf "Counterexample: guest-id = ~a\n" (evaluate guest-id result)))))


;; ---------------------------
;; IP 4: Registers must only be restored for the correct guest
;; Property: When restoring encrypted registers during VMRUN, they must belong to the currently executing guest.
;; ---------------------------

(define (check-register-restore-belongs-to-guest)
  (printf "\n[IP 4] Registers must only be restored for the correct guest\n")
  (printf "Property: Register state must not be restored to a guest from another guest's VMCB.\n\n")

  ;; Symbolic guest IDs
  (define-symbolic guest-A integer?)
  (define-symbolic guest-B integer?)
  (define-symbolic reg-val (bitvector 256))

  ;; Guest A enters VMEXIT and saves registers
  (add-guest guest-A 'RUNNING 1001 0 0 0 0 0 0)
  (set-guest-state guest-A 'RUNNING)
  (save-registers-to-vmcb guest-A reg-val)

  ;; Malicious attempt: assign guest B same VMCB entry
  (add-guest guest-B 'VMEXIT 2002 0 0 0 0 0 0)
  (hash-set! VMCB guest-B (hash-ref VMCB guest-A))

  ;; Try to restore for guest B
  (VMRUN guest-B)

  ;; Verify that guest B did not get A’s register state (flag should not be cleared)
  (define b-entry (get-guest guest-B))
  (define restored-encryption-flag (list-ref b-entry 9)) ;; should be #f after legitimate VMRUN

  ;; If register state restored improperly, encryption flag might be set wrong
  (define result (solve (assert restored-encryption-flag))) 

  (if (unsat? result)
      (printf "\n ✅ PASS: Guest cannot restore another guest’s registers.\n\n")
      (begin
        (printf "\n ❌ FAIL: Guest restored registers from another guest!\n")
        (printf "Counterexample: guest-A = ~a, guest-B = ~a\n"
                (evaluate guest-A result)
                (evaluate guest-B result)))))


;; ---------------------------
;; IP 5: State transitions must be rollback resistant
;; Property: A guest must not revert to a previous lifecycle state after progressing forward.
;; ---------------------------
(define (check-rollback-resistance)
  (printf "\n[IP 5] State transitions must be rollback resistant\n")
  (printf "Property: A guest must not revert to a previous lifecycle state after progressing forward.\n\n")

  (define-symbolic guest-id integer?)

  ;; Simulate a legal guest lifecycle up to RUNNING
  (transition-guest guest-id 'LAUNCH_START)
  (transition-guest guest-id 'LAUNCH_UPDATE_DATA)
  (transition-guest guest-id 'LAUNCH_FINISH)

  ;; Now attempt an invalid rollback transition (to LUPDATE)
  (define result
    (solve
     (assert
      (begin
        (transition-guest guest-id 'LAUNCH_START) ;; This should hit the (assert #f ...) inside transition-guest
        #t))))

  (if (unsat? result)
      (printf "\n ✅ PASS: Guest state transitions are rollback resistant.\n\n")
      (begin
        (printf "\n ❌ FAIL: Guest state was rolled back to earlier stage!\n")
        (printf "Counterexample: guest-id = ~a, current-state = ~a\n"
                (evaluate guest-id result)
                (evaluate (get-guest-state guest-id) result)))))


;; ---------------------------
;; IP 6: Register state must not be accessible after VMEXIT
;; Property: After a VMEXIT, the guest’s register state must be encrypted and
;; inaccessible to any observer or external agent.
;; ---------------------------

(define (check-register-integrity-after-vmexit)
  (printf "\n[IP 6] Register state must not be accessible after VMEXIT\n")
  (printf "Property: After VMEXIT, guest register state must be encrypted and not externally readable.\n\n")

  ;; Symbolic guest
  (define-symbolic guest-id integer?)

  ;; Setup guest and simulate transition to RUNNING
  (add-guest guest-id 'RUNNING 1001 0 0 0 0 0 0)
  (set-guest-state guest-id 'RUNNING)

  ;; Perform VMEXIT (registers should be saved and encrypted)
  (VMEXIT guest-id)

  ;; Access encrypted-registers flag and saved register state
  (define gctx (get-guest guest-id))
  (define reg-encrypted? (list-ref gctx 9)) ;; Index 9: encrypted flag
  (define reg-snapshot  (hash-ref VMCB guest-id #f))

  ;; Define violation: registers not encrypted, or still accessible as plain values
  (define result
    (solve (assert (or (not reg-encrypted?)
                       (not reg-snapshot)))))

  (if (unsat? result)
      (printf "\n ✅ PASS: Register state is encrypted and protected after VMEXIT.\n\n")
      (begin
        (printf "\n ❌ FAIL: Register state is exposed or unprotected after VMEXIT!\n")
        (printf "Counterexample: guest-id = ~a, encrypted? = ~a, snapshot = ~a\n"
                (evaluate guest-id result)
                (evaluate reg-encrypted? result)
                (evaluate reg-snapshot result)))))


;; ---------------------------
;; IP 7: Page version must be monotonic
;; Property: Page version numbers must only increase to prevent rollback.
;; ---------------------------

(define (check-monotonic-page-version)
  (printf "\n[IP 7] Page version must be monotonic\n")
  (printf "Property: Page version must not decrease to prevent rollback attacks.\n\n")

  ;; Symbolic guest and page
  (define-symbolic guest-id integer?)
  (define-symbolic page-addr integer?)

  ;; Guest owns the page
  (assign-page-to-guest page-addr guest-id)

  ;; Simulate a valid version first
  (set-page-version! page-addr 3)

  ;; Attempt to downgrade the version (simulate rollback)
  (set-page-version! page-addr 1)

  ;; Check if the downgrade was accepted (should not be)
  (define result (solve (assert (< (get-page-version page-addr) 3))))

  (if (unsat? result)
      (printf "\n ✅ PASS: Page version remains monotonic.\n\n")
      (begin
        (printf "\n ❌ FAIL: Page version was downgraded!\n")
        (printf "Counterexample: guest-id = ~a, page = ~a, version = ~a\n"
                (evaluate guest-id result)
                (evaluate page-addr result)
                (evaluate (get-page-version page-addr) result)))))


(check-launch-state-integrity)
(check-atomic-state-transition)
; (check-secrets-not-migrated)
(check-register-restore-belongs-to-guest)
(check-rollback-resistance)
(check-register-integrity-after-vmexit)
(check-monotonic-page-version)
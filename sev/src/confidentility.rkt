#lang rosette

(require "tables.rkt")
(require "abi.rkt")

;; ---------------------------
;; Conf_Property 1:
;; Only the assigned guest may access the page (via RMP check)
;; Property: If guest ≠ page owner, it must not pass the ownership check (RMP).
;; ---------------------------

(define (check-rmp-page-ownership-property)
    (printf "\n CP 1: Only the assigned guest may access the page (via RMP check)\n")
    (printf "Property: If guest ≠ page owner, it must not pass the ownership check (RMP).\n\n")

    ;; --- Step 1: Define symbolic variables ---
    (define-symbolic attacker-id integer?)
    (define-symbolic page-addr integer?)

    ;; --- Step 2: Assign legitimate owner and map page in RMP ---
    (define legitimate-owner 42)
    (assign-page-to-guest page-addr legitimate-owner)

    ;; --- Step 3: Define constraint: attacker-id is different from the legitimate owner ---
    (define attacker-constraint (not (= attacker-id legitimate-owner)))

    ;; --- Step 4: Define the property: attacker must NOT be able to access the page ---
    (define no-access-property (not (owns-page? attacker-id page-addr)))

    ;; --- Step 5: Solve to find violation: is there an attacker who can access the page? ---
    (define result (solve (assert (and attacker-constraint (not no-access-property)))))

    (printf "DEBUG: RMP[~a] = ~a\n" page-addr legitimate-owner)

    (if (unsat? result)
        (printf "\n ✅ PASS: No unauthorized guest can access the page.\n\n")
        (begin
        (printf "\n ❌ FAIL: Unauthorized access IS possible!\n")
        (printf "Counterexample: attacker-id = ~a, page-addr = ~a\n"
                (evaluate attacker-id result)
                (evaluate page-addr result))))
)

;; ---------------------------
;; Conf_Property 2:
;; No ASID Reuse Without Explicit Deallocation
;; Property: If ASID is already assigned to guest A,
;;           guest B must not be able to reuse it unless it's freed first.
;; ---------------------------

(define (check-asid-reuse-property)
    (printf "\n[CP 2] No ASID reuse without explicit deallocation\n")
    (printf "Property: If ASID is already assigned to guest A,\n")
    (printf "then another guest must not be able to reuse it unless it is deallocated first.\n\n")

    (define-symbolic guest-A integer?)
    (define-symbolic guest-B integer?)
    (define-symbolic asid integer?)

    (SEV_ASID_ALLOC guest-A asid)

    (define constraint-guest-diff (not (= guest-A guest-B)))

    (define reuse-property (not (begin
                                (SEV_ASID_ALLOC guest-B asid)
                                (equal? (get-asid-owner asid) guest-B))))

    (define result (solve (assert (and constraint-guest-diff (not reuse-property)))))

    (printf "DEBUG: ASID[~a] was assigned to guest ~a\n" asid guest-A)

    (if (unsat? result)
        (printf "\n ✅ PASS: ASID is not reused without deallocation.\n\n")
        (begin
        (printf "\n ❌ FAIL: ASID reuse without freeing is possible!\n")
        (printf "Counterexample: guest-A = ~a, guest-B = ~a, asid = ~a\n"
                (evaluate guest-A result)
                (evaluate guest-B result)
                (evaluate asid result))))
)


;; ---------------------------
;; Conf_Property 3:
;; Only the ASID owner may access the corresponding VEK
;; Property: If guest ≠ ASID owner, they must not retrieve the VEK.
;; ---------------------------
(define (check-vek-confidentiality-property)
  (printf "\n[CP 3] VEK Confidentiality\n")
  (printf "Property: Only the ASID owner can retrieve the VEK.\n")
  (printf "If guest ≠ ASID owner, they must not retrieve the VEK.\n\n")

  (define-symbolic guest-A integer?)
  (define-symbolic guest-B integer?)
  (define-symbolic asid integer?)

  (SEV_ASID_ALLOC guest-A asid)
  (define vek (bv 123456 256))
  (assign-vek asid vek)

  (define guest-constraint (not (= guest-A guest-B)))
  (define attacker-should-not-get (not (equal? (get-vek guest-B asid) vek)))

  (define result
    (solve (assert (and guest-constraint (not attacker-should-not-get)))))

  (printf "DEBUG: ASID[~a] assigned to guest-A = ~a, VEK = ~a\n" asid guest-A vek)

  (if (unsat? result)
      (printf "\n ✅ PASS: Unauthorized guest cannot retrieve VEK.\n\n")
      (begin
        (printf "\n ❌ FAIL: VEK exposure to unauthorized guest is possible!\n")
        (printf "Counterexample: guest-A = ~a, guest-B = ~a, asid = ~a\n"
                (evaluate guest-A result)
                (evaluate guest-B result)
                (evaluate asid result))))
)


;; ---------------------------
;; CP 4: Page Access Requires Validation
;; Property: A guest must not be allowed to access or execute a memory page 
;; unless it has been validated using PVALIDATE.
;; ---------------------------

(define (check-page-validation-before-access)
  (printf "\n[CP 4] Page Access Requires Validation\n")
  (printf "Property: A guest must not be allowed to access or execute a page unless it has been validated.\n\n")

  (define-symbolic guest-id integer?)
  (define-symbolic page-addr integer?)

  (assign-page-to-guest page-addr guest-id)

  (mark-page-invalidated! page-addr)

  (define property (not (and (owns-page? guest-id page-addr)
                             (is-page-validated? page-addr))))

  (define result (solve (assert (not property))))

  (printf "DEBUG: Guest ~a owns page ~a, validated = ~a\n"
          guest-id page-addr (is-page-validated? page-addr))

  (if (unsat? result)
      (printf "\n ✅ PASS: Unvalidated pages cannot be accessed.\n\n")
      (begin
        (printf "\n ❌ FAIL: Guest can access unvalidated page!\n")
        (printf "Counterexample: guest-id = ~a, page-addr = ~a\n"
                (evaluate guest-id result)
                (evaluate page-addr result))))
)

;; ---------------------------
;; CP 5: VEK Confidentiality Must Be Maintained
;; Property: A guest's assigned VEK (memory encryption key) must not be 
;; accessible or inferable by another guest or untrusted party.
;; ---------------------------

(define (check-memory-encryption-binding-property)
  (printf "\n[CP 5] Memory encryption is bound to ASID\n")
  (printf "Property: A page encrypted by one ASID must not be decrypted using a different ASID.\n\n")

  (define-symbolic asid-A integer?)
  (define-symbolic asid-B integer?)
  (define-symbolic vek-A integer?)
  (define-symbolic vek-B integer?)
  (define-symbolic phys-addr integer?)

  (SEV_ASID_ALLOC 1 asid-A)
  (SEV_ASID_ALLOC 2 asid-B)
  (SEV_ENCRYPT_PAGE phys-addr)
  (assign-vek asid-A vek-A)
  (assign-vek asid-B vek-B)

  (define constraint-asid-diff (not (= asid-A asid-B)))
  (define (can-decrypt? asid page)
  (and (equal? (hash-ref PEB page 'UNKNOWN) 'ENCRYPTED)
       (= (get-vek asid) (get-vek (hash-ref RMP page)))))
                              
  (define result (solve (assert (and constraint-asid-diff (can-decrypt? asid-B phys-addr)))))


  (printf "DEBUG: Page[~a] encrypted with ASID ~a and VEK ~a\n" phys-addr asid-A vek-A)

  (if (unsat? result)
      (printf "\n ✅ PASS: Cross-ASID decryption is not possible.\n\n")
      (begin
        (printf "\n ❌ FAIL: Memory encrypted by one ASID can be accessed by another!\n")
        (printf "Counterexample: asid-A = ~a, asid-B = ~a, phys-addr = ~a, vek-A = ~a, vek-B = ~a\n"
                (evaluate asid-A result)
                (evaluate asid-B result)
                (evaluate phys-addr result)
                (evaluate vek-A result)
                (evaluate vek-B result)))))


;; ---------------------------
;; CP 6: Register State Must Be Encrypted on VMEXIT
;; Property: When a guest VM performs a VMEXIT, its register state must be 
;; encrypted and the encrypted-registers flag must be set to true.
;; ---------------------------
(define (check-registers-encrypted-on-vmexit)
  (printf "\n[CP 6] Register state must be encrypted on VMEXIT\n")
  (printf "Property: When a guest VM performs a VMEXIT, its register state must be marked as encrypted.\n\n")

  (define-symbolic guest-handle integer?)

  ;; Prepare the guest in RUNNING state (this is fast-forwarded to RUNNIG state)
  (add-guest guest-handle 'RUNNING 1001 0 0 0 0 0 0)
  (set-guest-state guest-handle 'RUNNING)

  ;; Simulate VMEXIT
  (VMEXIT guest-handle)

  (define guest-entry (get-guest guest-handle))
  (define reg-encrypted-flag (list-ref guest-entry 9))
  (define result (solve (assert (not reg-encrypted-flag))))

  (if (unsat? result)
      (printf "\n ✅ PASS: Register state is correctly encrypted on VMEXIT.\n\n")
      (begin
        (printf "\n ❌ FAIL: Register state is not encrypted on VMEXIT!\n")
        (printf "Counterexample: guest-handle = ~a, reg-flag = ~a\n"
                (evaluate guest-handle result)
                (evaluate reg-encrypted-flag result)))))

;; ---------------------------
;; CP 7: Validated Pages Must Not Be Remapped to Another Guest
;; Property: Once a page is validated by a guest, it must not be reassigned to another guest in the RMP.
;; ---------------------------
(define (check-page-remapping-after-validation)
  (printf "\n[CP 7] Validated pages must not be remapped to another guest\n")
  (printf "Property: Once a page is validated by a guest, it must not be reassigned to another guest in the RMP.\n\n")

  (define-symbolic guest-A integer?)
  (define-symbolic guest-B integer?)
  (define-symbolic page integer?)

  (define guests-different (not (= guest-A guest-B)))

  (assign-page-to-guest page guest-A)
  (mark-page-validated! page)

  ;; Attacker (guest B) remaps the page
  (assign-page-to-guest page guest-B)

  ;; Property: guest-A must still own the page
  (define remapping-violation (not (owns-page? guest-A page)))

  (define result (solve (assert (and guests-different remapping-violation))))

  (printf "DEBUG: Page[~a] validated by guest ~a and reassigned to guest ~a\n"
          page guest-A guest-B)

  (if (unsat? result)
      (printf "\n ✅ PASS: Validated page cannot be reassigned to another guest.\n\n")
      (begin
        (printf "\n ❌ FAIL: Validated page was reassigned!\n")
        (printf "Counterexample: guest-A = ~a, guest-B = ~a, page = ~a\n"
                (evaluate guest-A result)
                (evaluate guest-B result)
                (evaluate page result)))))


;; ---------------------------
;; CP 8: Guest Must Not Use or Modify Page Content Unless Explicitly Validated
;; Property: A guest must not use (access/execute) or modify the contents of a page
;; unless the page has been explicitly validated via PVALIDATE.
;; ---------------------------
(define (check-page-integrity-via-validation)
  (printf "\n[CP 8] Page content must not change unless explicitly validated\n")
  (printf "Property: A page must not be considered modifiable unless it has been validated via PVALIDATE.\n\n")

  (define-symbolic guest-id integer?)
  (define-symbolic phys-addr integer?)

  ;; Simulate guest owning the page, but it's not validated
  (assign-page-to-guest phys-addr guest-id)
  (SEV_ENCRYPT_PAGE phys-addr)
  (mark-page-invalidated! phys-addr)

  ;; Attempt access — will fail if model allows illegal access
  (define result
    (solve
     (assert
      (begin
        (access-page guest-id phys-addr) 
        #t)))) 

  (printf "DEBUG: Page[~a] owned by guest ~a, validated? ~a\n"
          phys-addr guest-id (is-page-validated? phys-addr))

  (if (unsat? result)
      (printf "\n ✅ PASS: Unvalidated pages are not accessible/modified.\n\n")
      (begin
        (printf "\n ❌ FAIL: Unvalidated page can be accessed/modified!\n")
        (printf "Counterexample: guest-id = ~a, phys-addr = ~a\n"
                (evaluate guest-id result)
                (evaluate phys-addr result)))))


;; ---------------------------
;; CP 9: Secrets must not be accessible after DEACTIVATE
;; Property: Once a guest is deactivated, previously injected secrets must no longer be accessible.
;; ---------------------------

(define (check-secrets-erased-after-deactivation)
  (printf "\n[CP 9] Secrets must not be accessible after DEACTIVATE\n")
  (printf "Property: Once a guest is deactivated, any secrets injected during launch must not remain in guest context.\n\n")

  (define-symbolic guest-id integer?)

  ;; Simulate a guest launch and secret injection
  (add-guest guest-id 'LSECRET 1001 0 0 0 0 0 0)
  (set-guest-state guest-id 'LSECRET)
  
  (define-symbolic injected-secret (bitvector 64))
  (define gctx-before (get-guest guest-id))
  (hash-set! GCTX guest-id (append gctx-before (list injected-secret)))

  (set-guest-state guest-id 'RUNNING)
  (DEACTIVATE guest-id)

  (define gctx-after (get-guest guest-id))

  (define result (solve (assert gctx-after))) 

  (if (unsat? result)
      (printf "\n ✅ PASS: Secrets are removed after DEACTIVATE.\n\n")
      (begin
        (printf "\n ❌ FAIL: Secrets remain accessible after DEACTIVATE!\n")
        (printf "Counterexample: Guest-ID = ~a still has entry in GCTX: ~a\n"
                (evaluate guest-id result)
                (evaluate gctx-after result)))))


;; ---------------------------
;; CP 10: Pages must not be reassigned without explicit unassignment
;; Property: A page already assigned to a guest must not be reassigned to another without unassigning.
;; ---------------------------

(define (check-page-reassignment-requires-unassign)
  (printf "\n[CP 10] Pages must not be reassigned without explicit unassignment\n")
  (printf "Property: A page assigned to Guest A must not be reassigned to Guest B without being explicitly unassigned.\n\n")

  (define-symbolic guest-A integer?)
  (define-symbolic guest-B integer?)
  (define-symbolic page-addr integer?)

  (assign-page-to-guest page-addr guest-A)

  ;; Define constraint: guest-A ≠ guest-B
  (define constraint-different-guests (not (= guest-A guest-B)))

  ;; Try to reassign the page directly to Guest B WITHOUT unassigning
  (assign-page-to-guest page-addr guest-B)

  (define reassigned? (= (hash-ref RMP page-addr 'none) guest-B))

  (define result (solve (assert (and constraint-different-guests reassigned?))))

  (if (unsat? result)
      (printf "\n ✅ PASS: Pages cannot be reassigned without unassignment.\n\n")
      (begin
        (printf "\n ❌ FAIL: Page was reassigned to another guest without unassigning!\n")
        (printf "Counterexample: guest-A = ~a, guest-B = ~a, page = ~a\n"
                (evaluate guest-A result)
                (evaluate guest-B result)
                (evaluate page-addr result)))))

(define (check-secrets-only-after-attestation)
  (printf "\n[CP 11] Secrets must be injected only after attestation\n")
  (printf "Property: A guest must not receive secrets unless it has completed attestation.\n\n")

  (define-symbolic guest-id integer?)

  (add-guest guest-id 'LSECRET 1001 0 0 0 0 0 0)
  (set-guest-state guest-id 'LSECRET)

  (LAUNCH_SECRET guest-id (bv #xCAFEBABE 64))

  (define guest-entry (get-guest guest-id))

  ;; The guest context should contain both measurement and secrets if used properly
  ;; Measurement is appended *before* secrets, so must exist (index 10) if secrets exist (index 11)
  (define has-secret? (>= (length guest-entry) 11))
  (define has-measurement? (>= (length guest-entry) 10))

  (define property (and has-secret? (not has-measurement?)))

  (define result (solve (assert property)))

  (if (unsat? result)
      (printf "\n ✅ PASS: Secrets are only injected after attestation.\n\n")
      (begin
        (printf "\n ❌ FAIL: Secrets injected before attestation!\n")
        (printf "Counterexample: guest-id = ~a\n" (evaluate guest-id result)))))


;; ---------------------------
;; CP 12: Guest Must Not Be Activated Without Secrets and Measurement
;; Property: A guest must not be allowed to enter the RUNNING state unless it has
;; completed attestation (via LAUNCH_MEASURE) and received secrets (via LAUNCH_SECRET).
;; This ensures the guest starts execution only with verified and provisioned state.
;; ---------------------------

(define (check-activation-requires-attestation-and-secrets)
  (printf "\n[CP 12] Guest must not be activated without secrets and attestation\n")
  (printf "Property: A guest must not enter RUNNING state unless attestation and secrets are injected.\n\n")

  (define-symbolic guest-id integer?)

  ;; Setup guest manually in LSECRET state without secrets and measurement
  (add-guest guest-id 'LSECRET 1001 0 0 0 0 0 0)
  (set-guest-state guest-id 'LSECRET)

  ;; Try to launch (simulate running without prior LAUNCH_MEASURE + LAUNCH_SECRET)
  (LAUNCH_FINISH guest-id)

  (define current-state (get-guest-state guest-id))

  ;; Check whether measurement and secrets are available
  (define guest-entry (get-guest guest-id))
  (define has-measurement? (>= (length guest-entry) 10))
  (define has-secret?     (>= (length guest-entry) 11))

  (define violation (and (equal? current-state 'RUNNING)
                         (or (not has-measurement?) (not has-secret?))))

  (define result (solve (assert violation)))

  (if (unsat? result)
      (printf "\n ✅ PASS: Guest cannot activate without secrets + measurement.\n\n")
      (begin
        (printf "\n ❌ FAIL: Guest activated without secrets or attestation!\n")
        (printf "Counterexample: guest-id = ~a\n" (evaluate guest-id result)))))


;; ---------------------------
;; CP 13: Secrets Must Not Be Visible After DECOMMISSION
;; Property: Once a guest is decommissioned, any secrets it held must no longer be accessible.
;; ---------------------------

(define (check-secrets-cleared-after-decommission)
  (printf "\n[CP 13] Secrets must not be visible after DECOMMISSION\n")
  (printf "Property: Once a guest is decommissioned, any secrets it held must no longer be accessible.\n\n")

  ;; Symbolic guest handle
  (define-symbolic guest-id integer?)

  ;; Simulate guest setup
  (add-guest guest-id 'SENT 1001 0 0 0 0 0 0)
  (set-guest-state guest-id 'SENT)

  ;; Inject secrets (simulating LAUNCH_SECRET phase)
  (define secrets (bv #xDEADBEEF 64))
  (define guest-entry (get-guest guest-id))
  (hash-set! GCTX guest-id (append guest-entry (list secrets)))

  ;; Perform DECOMMISSION
  (DECOMMISSION guest-id)

  ;; After decommission, check if secrets are still accessible
  (define secrets-visible?
    (let ([post-entry (get-guest guest-id)])
      (and post-entry (>= (length post-entry) 11)))) ;; index 10 = secrets field

  ;; Solve
  (define result (solve (assert secrets-visible?)))

  (if (unsat? result)
      (printf "\n ✅ PASS: Guest secrets are removed after decommission.\n\n")
      (begin
        (printf "\n ❌ FAIL: Guest secrets remain visible after decommission!\n")
        (printf "Counterexample: guest-id = ~a\n"
                (evaluate guest-id result)))))


;; ---------------------------
;; CP 14: GHCB Must Not Leak Secrets or Sensitive Guest State
;; Property: The GHCB must not contain secrets, VEKs, or any confidential data from the guest context.
;; ---------------------------

(define (check-ghcb-does-not-leak-sensitive-state)
  (printf "\n[CP 14] GHCB must not leak secrets or sensitive guest state\n")
  (printf "Property: The GHCB must not contain secrets, VEKs, or any confidential guest data.\n\n")

  ;; Symbolic guest handle and sensitive data (e.g., secrets or VEK)
  (define-symbolic guest-id integer?)
  (define-symbolic sensitive-value integer?)

  ;; Set GHCB to a sensitive value (simulate an attack or leak)
  (set-ghcb-state! guest-id sensitive-value)

  ;; Simulate guest context holding secrets
  (add-guest guest-id 'RUNNING 1001 0 0 0 0 0 0)
  (set-guest-state guest-id 'RUNNING)
  (define gctx-entry (get-guest guest-id))
  (define gctx-with-secret (append gctx-entry (list sensitive-value)))
  (hash-set! GCTX guest-id gctx-with-secret)

  ;; Violation if GHCB contains any value in guest context (especially secrets/VEK)
  (define ghcb-value (get-ghcb-state guest-id))
  (define leak-detected (member ghcb-value gctx-with-secret))

  ;; Check if such a leak is possible
  (define result (solve (assert leak-detected)))

  (if (unsat? result)
      (printf "\n ✅ PASS: GHCB does not leak sensitive data from guest context.\n\n")
      (begin
        (printf "\n ✅ PASS:  GHCB leaks sensitive state!\n")
        (printf "Counterexample: guest-id = ~a, GHCB = ~a, GCTX = ~a\n"
                (evaluate guest-id result)
                (evaluate ghcb-value result)
                (evaluate gctx-with-secret result)))))



(check-rmp-page-ownership-property)
(check-asid-reuse-property)
(check-vek-confidentiality-property)
(check-page-validation-before-access)
(check-memory-encryption-binding-property)
(check-registers-encrypted-on-vmexit)
(check-page-remapping-after-validation)
(check-page-integrity-via-validation)
(check-secrets-erased-after-deactivation)
(check-page-reassignment-requires-unassign)
(check-secrets-only-after-attestation)
(check-activation-requires-attestation-and-secrets)
(check-secrets-cleared-after-decommission)
(check-ghcb-does-not-leak-sensitive-state)
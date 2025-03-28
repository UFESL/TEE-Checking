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

  ;; Constraints
  (define guests-different (not (= guest-A guest-B)))

  ;; Assign page to guest A and validate it
  (assign-page-to-guest page guest-A)
  (mark-page-validated! page)

  ;; Attacker (guest B) remaps the page
  (assign-page-to-guest page guest-B)

  ;; Property: guest-A must still own the page (i.e., no reassignment allowed)
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


(check-rmp-page-ownership-property)
(check-asid-reuse-property)
(check-vek-confidentiality-property)
(check-page-validation-before-access)
(check-memory-encryption-binding-property)
(check-registers-encrypted-on-vmexit)
(check-page-remapping-after-validation)

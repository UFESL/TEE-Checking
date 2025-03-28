#lang rosette

(require "tables.rkt")

;; ---------------------------
;; Conf_Property 1:
;; Only the assigned guest may access the page (via RMP check)
;; Property: If guest ≠ page owner, it must not pass the ownership check (RMP).
;; ---------------------------

(define (check-rmp-page-ownership-property)
    (printf "\n[Conf_Property 1] Only the assigned guest may access the page (via RMP check)\n")
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

    ;; --- Step 6: Print RMP Table for debug ---
    (printf "DEBUG: RMP[~a] = ~a\n" page-addr legitimate-owner)

    ;; --- Step 7: Report Result ---
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
    (printf "\n[Conf_Property 2] No ASID reuse without explicit deallocation\n")
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


(check-rmp-page-ownership-property)
(check-asid-reuse-property)
#lang rosette

;; Step 1: Define a Function to Verify
(define (double x) (* 2 x))

;; Step 2: Declare a Symbolic Variable
(define-symbolic x integer?)

;; Step 3: Define a Property (Correctness Condition)
(define property (>= (double x) 0))  ;; Don't use (assert ...) here

;; Step 4: Check if the Property Holds
(define result (verify (assert property)))  ;; Wrap the property with assert here

;; Step 5: Display the Result
(displayln result)

;; Constrain x to be greater than 0
(define constraints (> x -5))

;; Define the property to verify
(define prop (>= (double x) 0))

;; Solve for a violation: is there an x > 0 where the property FAILS?
(define result2 (solve (assert (and constraints (not prop)))))

;; Display the result
(printf "\n[Property Check] For x > 0, is double(x) ≥ 0?\n")
(if (unsat? result2)
    (printf "✅ PASS: Property holds for all x > 0\n")
    (begin
      (printf "❌ FAIL: Property violated!\n")
      (printf "Counterexample: x = ~a\n" (evaluate x result2))))
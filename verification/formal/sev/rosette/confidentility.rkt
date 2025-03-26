#lang rosette

;; Step 1: Define a Function to Verify
(define (double x) (* 2 x))

;; Step 2: Declare a Symbolic Variable
(define-symbolic x integer?)

;; Step 3: Define a Property (Correctness Condition)
(define property (assert (>= (double x) 0)))

;; Step 4: Check if the Property Holds
(define result (verify property))

;; Step 5: Display the Result
(displayln result)  ;; Correct way to print the verification result

#lang rosette

(require (file "tables.rkt"))
(require "tdx_lib.rkt")
(require "cache_instance_hkid.rkt")

(displayln "Proof Confidentaility")

(define bv28 (bitvector 28))

; (bv28? (bv 3 28))


(define-symbolic pa1 bv28)
(define-symbolic repl-way integer?)
(define-symbolic hkid1 hkid2 integer?)

; (define a (extract 27 12 pa1))
; (extract 11 4 pa1)

; (bitvector->integer (extract 27 12 pa1))

; Simulate two cache accesses with different HKIDs for the same PA and repl-way
(define-values (hit1 way1 data1) (query-cache pa1 repl-way hkid1))
(define-values (hit2 way2 data2) (query-cache pa1 repl-way hkid2))

; Confidentiality assertion:
; Assert that if hkid1 and hkid2 are different, both cannot have cache hits for the same PA
(define confidentiality-assertion
  (assert (not (and hit1 hit2 (not (= hkid1 hkid2))))))

; Solve the assertion
(define result (solve (confidentiality-assertion)))

(displayln result)

; (match result
;   [('unsat _) (displayln "Confidentiality property upheld: Unauthorized access is denied.")]
;   [('sat sol) (displayln "Confidentiality property violated: There's a potential leak.")]
;   [else (displayln "Unexpected result from solver.")])




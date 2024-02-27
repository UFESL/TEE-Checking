; Instance 1
; Two TD's running
#lang rosette


(require (file "tables.rkt"))
(require "tdx_lib.rkt")
; (require "cache_instance_hkid.rkt")

(displayln "Instance 1")

; Instance1 configuration
(define pa1 100000)
(define pa2 107000)

(define hkid1 5)
(define hkid2 6)

(define data1 21345)
(define data2 10098)

(printf "TD creation with hpa ~a and HKID ~a\n" pa1 hkid1)
(printf "TD creation with hpa ~a and HKID ~a\n" pa2 hkid2)
(define temp_tdr1 (TDH_MNG_CREATE pa1 hkid1))
(define temp_tdr2 (TDH_MNG_CREATE pa2 hkid2))
(displayln (TDR-LIFECYCLE_STATE temp_tdr1))
(displayln (TDR-LIFECYCLE_STATE temp_tdr2))
(displayln PAMT)

(displayln "Step1 : TD creation Done : Life Cycle HKID Assigned (1)")

(define pamt_entry1 (hash-ref PAMT pa1))
(displayln (PAMT_entry-PAGE_TYPE pamt_entry1))
(displayln (TDR-LIFECYCLE_STATE temp_tdr1))

(set! temp_tdr1 (TDH_MNG_KEY_CONFIG pa1 temp_tdr1))
(displayln KET)
(displayln (PAMT_entry-PAGE_TYPE pamt_entry1))
(displayln (TDR-LIFECYCLE_STATE temp_tdr1))
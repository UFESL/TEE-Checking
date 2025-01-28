; TDX tables and configurations
#lang rosette
(require data/bit-vector)   ; bitvectors
(require "tdx_lib.rkt")     ; various state defintions and helper functions

;********************* Tables *********************

; See p56 for description of key management tables for confidentiality

; GPA : guest physical address, HPA : host physical address

; (S)EPT -> maps GPA to HPA and page state (shared bit, EPT entry state)
(define secure_EPT (make-hash))
(define-struct secure_EPT_entry (host_physical_address GPA_SHARED state))
(define/contract secure_EPT-contract
    (hash/c integer? secure_EPT_entry? #:flat? #t)
    secure_EPT)

; KET[HKID] -> TD's ephemeral encryption key
(define KET (make-hash))
(define/contract KET-contract
    (hash/c integer? bitvector? #:flat? #t)
    KET)

; KOT[HKID] -> State (free, assigned, reclaimed, flushed, n/a (hkid free), reserved)
; See table 4.3 in TDX specification for state table, table 4.1 for KET and KOT
(define KOT (make-hash))
(define/contract KOT-contract
    (hash/c integer? integer? #:flat? #t)
    KOT)

; TDR : Trust Domain Root
; See table 23.3 on p.171
(define-struct TDR (INIT FATAL NUM_TDCX TDCX_PA CHLDCNT LIFECYCLE_STATE HKID PKG_CONFIG_BITMAP FINALIZED RUNNING))


; TDCS : Trust Domain Control Structure
; See table 23.5 on p.172 (All the fields are not implemented here for simplicity)
(define-struct TDCS (FINALIZED NUM_VCPUS NUM_ASSOC_VCPUS ATTRIBUTES EPTP TSC_OFFSET TSC_MULTIPLIER))


; TDVPS : Trust Domain Virtual Process State
; See table 23.9 on p.176 (All the fields are not implemented here for simplicity)
(define-struct TDVPS (VCPU_STATE LAUNCHED VCPU_INDEX NUM_TDVPX TDVPS_PAGE_PA ASSOC_LPID ASSOC_HKID VCPU_EPOCH CPUID_SUPERVISOR_VE))


; PAMT (p67-68)
; Note that the OWNER field is a bit field from the pa of the TDR, here it
; could probably be some TD_ID instead
; EPOCH is only intended for pages of type PT_REG or PT_EPT
; PAMTs are more complex than this because there are multiple page sizes but
; I don't think that'll impact confidentiality.
(define PAMT (make-hash))
(define-struct PAMT_entry (PAGE_TYPE OWNER BEPOCH))
(define/contract PAMT-contract
    (hash/c integer? PAMT_entry? #:flat? #t)
    PAMT)

; Need some way to model what is in the cache at any given time so that we can model
; flushing the cache during context switches or TD teardown. So I think a map of like
; physical addresses to a cache line structure, where the data field doesn't matter but
; we need to have the TD owner bit and HKID at the very least. Maybe the MAC too

; So on p120 it specifies the components for Ci mode, as the data, a tweaked pa, the TD owner bit, and the MAC key
(define cache (make-hash))
(define-struct cache_entry (TD_OWNER HKID MAC DATA))
(define/contract cache-contract
    (hash/c integer? cache_entry? #:flat? #t)
    cache)

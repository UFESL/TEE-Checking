#lang rosette

(require "tables.rkt")

;; LAUNCH_START: Initializes a new SEV guest
(define (LAUNCH_START handle asid policy)
  (define current-state (get-guest-state handle))
  (printf "DEBUG: Current state of guest ~a is: ~a\n" handle current-state)
  (when (equal? current-state 'UNINIT)
    (add-guest handle 'LUPDATE asid policy 0 0 0 0 0) ;; Initialize guest with zeroed encryption keys
    (SEV_ASID_ALLOC handle asid)
    (set-guest-state handle 'LUPDATE)))


;; LAUNCH_UPDATE_DATA: Encrypts guest memory pages
(define (LAUNCH_UPDATE_DATA handle memory-pages)
  (define current-state (get-guest-state handle))
  (printf "DEBUG: Current state of guest ~a is: ~a\n" handle current-state)
  (when (equal? current-state 'LUPDATE)
    (for-each SEV_ENCRYPT_PAGE memory-pages) ;; Encrypt all pages
    (set-guest-state handle 'LSECRET)))


;; LAUNCH_MEASURE: Computes attestation measurement
(define (LAUNCH_MEASURE handle)
  (define current-state (get-guest-state handle))
  (printf "DEBUG: Current state of guest ~a is: ~a\n" handle current-state)
  (when (equal? current-state 'LSECRET)
    (define guest (get-guest handle))
    (define measurement (bv #xDEADBEEF 64)) ;; Placeholder for actual measurement computation
    (hash-set! GCTX handle (append guest (list measurement))) ;; Store measurement
    (set-guest-state handle 'LSECRET))) ;; Remains in LSECRET state


;; LAUNCH_SECRET: Injects encrypted secrets into guest memory
(define (LAUNCH_SECRET handle secrets)
  (define current-state (get-guest-state handle))
  (when (equal? current-state 'LSECRET)
    (define guest (get-guest handle))
    (define encrypted-secrets (bv #xCAFEBABE 64)) ;; Placeholder for actual encryption
    (hash-set! GCTX handle (append guest (list encrypted-secrets))) ;; Store encrypted secrets
    (set-guest-state handle 'LSECRET))) ;; Remains in LSECRET state


;; LAUNCH_FINISH: Finalizes guest launch
(define (LAUNCH_FINISH handle)
  (define current-state (get-guest-state handle))
  (when (equal? current-state 'LSECRET)
    (set-guest-state handle 'RUNNING)))


;; ACTIVATE: Assigns ASID and loads encryption keys
(define (ACTIVATE handle)
  (define current-state (get-guest-state handle))
  (when (equal? current-state 'RUNNING)
    ;; Generate a new encryption key (symbolic)
    (define vek (bv 128 256))  ;; 256-bit symbolic AES key
    ;; Retrieve ASID from guest context
    (define guest (get-guest handle))
    (define asid (cadr guest))  ;; ASID is stored in the second field
    ;; Assign VEK to ASID
    (assign-vek asid vek)
    ;; Update Guest Context with VEK
    (hash-set! GCTX handle (append guest (list vek)))
    ;; Transition guest state to RUNNING
    (set-guest-state handle 'RUNNING)))


;; DEACTIVATE: Deallocates ASID and clears encryption keys
(define (DEACTIVATE handle)
  (define current-state (get-guest-state handle))
  (when (equal? current-state 'RUNNING)
    ;; Retrieve ASID from guest context
    (define guest (get-guest handle))
    (define asid (cadr guest))  ;; ASID is stored in the second field
    ;; Remove encryption key
    (delete-vek asid)
    ;; Free ASID
    (SEV_ASID_FREE asid)
    ;; Reset guest context
    (hash-remove! GCTX handle)
    ;; Transition guest state to UNINIT
    (set-guest-state handle 'UNINIT)))


    ;; SEND_START: Prepares guest for migration
(define (SEND_START handle)
  (define current-state (get-guest-state handle))
  (when (equal? current-state 'RUNNING)
    (set-guest-state handle 'SUPDATE)))  ;; Transition to migration state


;; SEND_UPDATE_DATA: Encrypts guest state before migration
(define (SEND_UPDATE_DATA handle memory-pages)
  (define current-state (get-guest-state handle))
  (when (equal? current-state 'SUPDATE)
    (for-each SEV_ENCRYPT_PAGE memory-pages) ;; Encrypt pages before sending
    (set-guest-state handle 'SUPDATE))) ;; Stay in SUPDATE until transfer completes


;; RECEIVE_UPDATE_DATA: Restores guest memory after migration
(define (RECEIVE_UPDATE_DATA handle memory-pages)
  (define current-state (get-guest-state handle))
  (when (equal? current-state 'RUPDATE)
    (for-each SEV_DECRYPT_PAGE memory-pages) ;; Decrypt received pages
    (set-guest-state handle 'RUNNING)))  ;; Guest is now fully active


;; DECOMMISSION: Securely deletes guest encryption key
(define (DECOMMISSION handle)
  (define current-state (get-guest-state handle))
  (when (equal? current-state 'SENT)
    (define guest (get-guest handle))
    (define asid (cadr guest)) ;; Retrieve ASID
    
    ;; Securely remove encryption keys and ASID
    (delete-vek asid)
    (SEV_ASID_FREE asid)
    
    ;; Remove guest entry
    (hash-remove! GCTX handle)
    
    ;; Reset guest state
    (set-guest-state handle 'UNINIT)))


(provide LAUNCH_START LAUNCH_UPDATE_DATA LAUNCH_MEASURE LAUNCH_SECRET LAUNCH_FINISH ACTIVATE DEACTIVATE SEND_START SEND_UPDATE_DATA RECEIVE_UPDATE_DATA DECOMMISSION)    
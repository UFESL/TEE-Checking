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
    ;; Encrypt and initialize metadata for each memory page
    (for-each (lambda (addr)
                (SEV_ENCRYPT_PAGE addr)            ; Mark encrypted in PEB
                (mark-page-invalidated! addr)      ; Not yet validated by guest
                (set-page-version! addr 1))        ; Initialize version for rollback protection
              memory-pages)
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
    ;; For each page: decrypt and validate integrity
    (for-each
     (lambda (addr)
       (SEV_DECRYPT_PAGE addr)                        ; Decrypt the page
       (PVALIDATE addr handle 1))                     ; Validate encryption, RMP ownership, version freshness
     memory-pages)
    ;; If all validations pass, transition guest to RUNNING
    (set-guest-state handle 'RUNNING)))


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


;; Function to toggle register encryption state
(define (set-register-encryption! handle encrypted?)
  (when (hash-has-key? GCTX handle)
    (define guest (hash-ref GCTX handle))
    (hash-set! GCTX handle (list (car guest) (cadr guest) (caddr guest) (cadddr guest)
                                 (list-ref guest 4) (list-ref guest 5) (list-ref guest 6)
                                 (list-ref guest 7) (list-ref guest 8) encrypted?))))  ;; Update encrypted-registers


(define (generate-symbolic-registers)
  ;; Create a symbolic 256-bit register snapshot
  (define-symbolic* rstate (bitvector 256))
  rstate)

;; Save encrypted symbolic register state to the VMCB
(define (save-registers-to-vmcb guest_handle enc-regs)
  (hash-set! VMCB guest_handle enc-regs))

;; Load encrypted registers from the VMCB for a given guest
(define (restore-registers-from-vmcb guest_handle)
  (hash-ref VMCB guest_handle #f))  ;; Return stored encrypted register state (or #f if not found)



;; External VMEXIT function (triggered by the platform)
(define (VMEXIT handle)
  (define current-state (get-guest-state handle))
  (when (equal? current-state 'RUNNING)
    (save-registers-to-vmcb handle (generate-symbolic-registers)) ;; Encrypt and save registers
    (set-register-encryption! handle #t)  ;; Mark registers as encrypted
    (set-guest-state handle 'VMEXIT)))  ;; Transition guest state


;; External VMRUN function (resumes guest execution)
(define (VMRUN handle)
  (define current-state (get-guest-state handle))
  (when (equal? current-state 'VMEXIT)
    (define restored-registers (restore-registers-from-vmcb handle)) ;; Decrypt and restore registers
    (set-register-encryption! handle #f)  ;; Mark registers as decrypted
    (set-guest-state handle 'RUNNING)))   ;; Transition guest state    


;; PVALIDATE: Validates a guest page before execution
(define (PVALIDATE phys_addr handle expected-version)
  ;; 1. Check encryption
  (define page-status (hash-ref PEB phys_addr 'UNKNOWN))
  (assert (equal? page-status 'ENCRYPTED) "Integrity violation: Page not encrypted!")

  ;; 2. Check guest ownership
  (define owner (hash-ref RMP phys_addr #f))
  (assert (equal? owner handle) "Unauthorized access: Guest does not own this page!")

  ;; 3. Check version freshness
  (define actual-version (get-page-version phys_addr))
  (assert (>= actual-version expected-version)
          "Rollback detected: Page version is older than expected!")

)

;; Enforce page validation before allowing guest execution
(define (transition-guest handle event)
  (define current-state (hash-ref GSTATE handle 'UNINIT))
  (match (list current-state event)
    [(list 'LUPDATE 'PVALIDATE) (set-guest-state handle 'LSECRET)] ;; Page validated, allow state change
    [(list 'LSECRET 'LAUNCH_FINISH) (set-guest-state handle 'RUNNING)]
    [(list 'RUNNING 'SEND_START) (set-guest-state handle 'SUPDATE)]
    [(list 'SUPDATE 'SEND_FINISH) (set-guest-state handle 'SENT)]
    [(list 'SENT 'DECOMMISSION) (set-guest-state handle 'UNINIT)]
    [_ (assert #f "Security violation: Invalid guest lifecycle transition!")]
  ))


(provide LAUNCH_START LAUNCH_UPDATE_DATA LAUNCH_MEASURE LAUNCH_SECRET LAUNCH_FINISH ACTIVATE DEACTIVATE SEND_START SEND_UPDATE_DATA RECEIVE_UPDATE_DATA DECOMMISSION)    
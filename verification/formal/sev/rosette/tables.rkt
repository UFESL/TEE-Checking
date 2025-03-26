#lang rosette

#|
Guest Context Table 
Maps guest handles to their state and encryption properties
|#

(define GCTX (make-hash))

(define/contract GCTX-contract
  (hash/c integer? (list/c symbol? integer? integer? integer? integer? integer? integer? integer? integer? boolean?))
  GCTX)

;; Add a new guest entry to the GCTX table
(define (add-guest handle state asid policy vek tek tik nonce ms  #:vmpl [vmpl 0])
  (hash-set! GCTX handle (list state asid policy vek tek tik nonce ms vmpl #f)))

;; Retrieve a guest entry from GCTX
(define (get-guest handle)
  (hash-ref GCTX handle #f))

;; Update guest state in GCTX
(define (update-guest-state handle new-state)
  (when (hash-has-key? GCTX handle)
    (define guest (hash-ref GCTX handle))
    (hash-set! GCTX handle (cons new-state (cdr guest)))))


;; ASID Table: Maps ASIDs to guest handles
(define ASIDT (make-hash))

(define/contract ASIDT-contract
  (hash/c integer? integer?)
  ASIDT)

;; Allocate an ASID to a guest
(define (SEV_ASID_ALLOC handle asid)
  (when (not (hash-has-key? ASIDT asid))
    (hash-set! ASIDT asid handle)))

;; Free an ASID
(define (SEV_ASID_FREE asid)
  (when (hash-has-key? ASIDT asid)
    (hash-remove! ASIDT asid)))

;; Retrieve the owner of an ASID
(define (get-asid-owner asid)
  (hash-ref ASIDT asid #f))


;; Page Encryption Table: Maps physical addresses to encryption status
(define PEB (make-hash))

(define/contract PEB-contract
  (hash/c integer? symbol?)
  PEB)

;; Mark a page as encrypted
(define (SEV_ENCRYPT_PAGE phys_addr)
  (hash-set! PEB phys_addr 'ENCRYPTED))

;; Mark a page as decrypted
(define (SEV_DECRYPT_PAGE phys_addr)
  (hash-set! PEB phys_addr 'DECRYPTED))

;; Check if a page is encrypted
(define (is-page-encrypted? phys_addr)
  (equal? (hash-ref PEB phys_addr 'UNKNOWN) 'ENCRYPTED))


;; Guest Policy Table: Stores security policies for each guest
(define GuestPolicy (make-hash))

(define/contract GuestPolicy-contract
  (hash/c integer? (list/c boolean? boolean? boolean? boolean? boolean? boolean?))
  GuestPolicy)

;; Set policy restrictions for a guest
(define (set-guest-policy handle nodbg noks es nosend domain sev)
  (hash-set! GuestPolicy handle (list nodbg noks es nosend domain sev)))

;; Retrieve a guest's policy
(define (get-guest-policy handle)
  (hash-ref GuestPolicy handle #f))

;; Check if debugging is allowed for a guest
(define (is-debugging-allowed? handle)
  (not (car (hash-ref GuestPolicy handle '(#t #t #t #t #t #t)))))

;; Check if migration is allowed for a guest
(define (is-migration-allowed? handle)
  (not (list-ref (hash-ref GuestPolicy handle '(#t #t #t #t #t #t)) 3)))


;; Guest State Machine: Tracks state transitions of each guest
(define GSTATE (make-hash))

(define/contract GSTATE-contract
  (hash/c integer? symbol?)
  GSTATE)

;; Set the state of a guest in both GSTATE and GCTX
(define (set-guest-state handle new-state)
  (hash-set! GSTATE handle new-state)  ;; Update quick state tracking
  (update-guest-state handle new-state))  ;; Call function to update GCTX

;; Retrieve the state of a guest
(define (get-guest-state handle)
  (hash-ref GSTATE handle 'UNINIT))

;; Transition guest state based on lifecycle events
(define (transition-guest handle event)
  (define current-state (hash-ref GSTATE handle 'UNINIT))
  (match (list current-state event)
    [(list 'UNINIT 'LAUNCH_START) (set-guest-state handle 'LUPDATE)]
    [(list 'LUPDATE 'LAUNCH_UPDATE_DATA) (set-guest-state handle 'LSECRET)]
    [(list 'LSECRET 'LAUNCH_FINISH) (set-guest-state handle 'RUNNING)]
    [(list 'RUNNING 'SEND_START) (set-guest-state handle 'SUPDATE)]
    [(list 'SUPDATE 'SEND_FINISH) (set-guest-state handle 'SENT)]
    [(list 'SENT 'DECOMMISSION) (set-guest-state handle 'UNINIT)]
    [_ (error "Invalid Transition!")]))


;; Memory Encryption Key Table: Maps ASIDs to VEKs (encryption keys)
(define MEKT (make-hash))

(define/contract MEKT-contract
  (hash/c integer? integer?)
  MEKT)

;; Assign a VEK to an ASID
(define (assign-vek asid vek)
  (hash-set! MEKT asid vek))

;; Retrieve a VEK for an ASID
(define (get-vek asid)
  (hash-ref MEKT asid #f))

;; Delete a VEK from the table
(define (delete-vek asid)
  (hash-remove! MEKT asid))

;; ----------------------------------
;; GHCB: Guest-Hypervisor Communication Block
;; Controls what the guest explicitly exposes to the hypervisor
(define GHCB (make-hash))

;; GHCB[guest_handle] => 'none | 'partial | 'full
(define (set-ghcb-state! guest_handle state)
  (hash-set! GHCB guest_handle state))

(define (get-ghcb-state guest_handle)
  (hash-ref GHCB guest_handle 'none))

;; ----------------------------------
;; VMCB: Virtual Machine Control Block (register snapshot)
(define VMCB (make-hash))

;; Save encrypted register state to VMCB on VMEXIT
(define (save-registers-to-vmcb guest_handle encrypted-registers)
  (hash-set! VMCB guest_handle encrypted-registers))

;; Restore register state from VMCB on VMRUN
(define (load-registers-from-vmcb guest_handle)
  (hash-ref VMCB guest_handle #f))

;; ----------------------------------
;; RMP: Reverse Map Table (tracks memory ownership)
(define RMP (make-hash))

;; Assign page ownership to guest
(define (assign-page-to-guest phys_addr guest_handle)
  (hash-set! RMP phys_addr guest_handle))

;; Remove page ownership (e.g., on deallocation)
(define (unassign-page phys_addr)
  (hash-remove! RMP phys_addr))

;; Check if a guest owns a given physical page
(define (owns-page? guest_handle phys_addr)
  (equal? (hash-ref RMP phys_addr 'none) guest_handle))

;; ----------------------------------
;; VMPL: Virtual Machine Privilege Level
(define VMPL (make-hash))

;; Set the VMPL for a guest
(define (set-vmpl guest_handle level)
  (hash-set! VMPL guest_handle level))

;; Get the VMPL of a guest
(define (get-vmpl guest_handle)
  (hash-ref VMPL guest_handle 0)) ;; Default to highest privilege (VMPL0)

;; Check if current guest has permission (≤ required level)
(define (has-vmpl-privilege? guest_handle required)
  (<= (get-vmpl guest_handle) required))

;; ----------------------------------
;; PageVersion: Track freshness/version of memory pages
(define PageVersion (make-hash))

;; Set version of a page
(define (set-page-version! phys_addr version)
  (hash-set! PageVersion phys_addr version))

;; Get version of a page
(define (get-page-version phys_addr)
  (hash-ref PageVersion phys_addr 0))

;; ----------------------------------
;; PVALIDATE Flag Table: Track whether page is validated
(define PVALIDATE-Flag (make-hash))

;; Mark a page as validated
(define (mark-page-validated! phys_addr)
  (hash-set! PVALIDATE-Flag phys_addr #t))

;; Mark a page as invalidated
(define (mark-page-invalidated! phys_addr)
  (hash-set! PVALIDATE-Flag phys_addr #f))

;; Check if a page is validated
(define (is-page-validated? phys_addr)
  (hash-ref PVALIDATE-Flag phys_addr #f))

(provide GHCB VMCB RMP VMPL PageVersion PVALIDATE-Flag
         set-ghcb-state! get-ghcb-state
         save-registers-to-vmcb load-registers-from-vmcb
         assign-page-to-guest unassign-page owns-page?
         set-vmpl get-vmpl has-vmpl-privilege?
         set-page-version! get-page-version
         mark-page-validated! mark-page-invalidated! is-page-validated?)


(provide GCTX PEB GSTATE get-guest-state set-guest-state get-guest SEV_ASID_ALLOC SEV_ASID_FREE SEV_ENCRYPT_PAGE SEV_DECRYPT_PAGE assign-vek delete-vek)

(provide add-guest get-guest update-guest-state set-guest-state get-guest-state
         SEV_ASID_ALLOC SEV_ASID_FREE get-asid-owner
         SEV_ENCRYPT_PAGE SEV_DECRYPT_PAGE is-page-encrypted?
         set-guest-policy get-guest-policy is-debugging-allowed? is-migration-allowed?
         transition-guest assign-vek delete-vek get-vek)
  


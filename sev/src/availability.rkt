(define (check-hypervisor-regains-control trace)
  ;; trace is a list of machine states (mi, mi+1, ...)
  (for ([i (in-range (length trace))])
    (define mi (list-ref trace i))
    (when (equal? (curr mi) 'v) ;; VM is executing
      (define next-h (ormap (lambda (j)
                              (equal? (curr (list-ref trace j)) 'h))
                            (range i (length trace))))
      (assert next-h))))


(define (check-guest-progress trace handle)
  ;; handle is the guest identifier
  (for ([i (in-range (length trace))])
    (define mi (list-ref trace i))
    (define state (get-guest-state handle mi))
    (when (and (equal? (curr mi) 'h)
               (guest-ready? state)) ; define guest-ready? for RUNNABLE or READY
      (define progressed (ormap (lambda (j)
                                  (not (equal? (get-guest-state handle (list-ref trace j))
                                               state)))
                                (range (+ i 1) (length trace))))
      (assert progressed))))

#lang rosette

; Define the cache parameters
(define kmax-cache-set-index 256)  ; Assuming a cache with 256 sets
(define kmax-cache-way-index 4)    ; Assuming 4-way set associative cache

; Define the cache state variables
(define cache-valid-map (make-hash))
(define cache-tag-map (make-hash))
(define cache-data-map (make-hash)) ; Define a new hash map for storing data

; Procedure to initialize the cache
(define (init-cache)
  (for ([i (in-range kmax-cache-set-index)])
    (for ([w (in-range kmax-cache-way-index)])
      (hash-set! cache-valid-map (cons i w) #f)  ; Set cache line as invalid
      (hash-set! cache-tag-map (cons i w) 0))))  ; Initialize tag with a default value

; Function to calculate the cache set index from an address
(define (address-to-set-index address)
  (remainder address kmax-cache-set-index))

; Function to calculate the tag from an address
(define (address-to-tag address)
  (quotient address kmax-cache-set-index))

; Function to simulate writing to the cache
(define (write-to-cache address data)
  (let ([set-index (address-to-set-index address)]
        [tag (address-to-tag address)])
    (if (and (hash-ref cache-valid-map (cons set-index 0) #f)  ; Check if the cache line is valid
             (= (hash-ref cache-tag-map (cons set-index 0) -1) tag))  ; Check if the tag matches
        (begin  ; Write hit: Update data
          (hash-set! cache-data-map (cons set-index 0) data)
          'write-hit)
        (begin  ; Write miss: Update cache line, tag, and data
          (hash-set! cache-valid-map (cons set-index 0) #t)
          (hash-set! cache-tag-map (cons set-index 0) tag)
          (hash-set! cache-data-map (cons set-index 0) data)
          'write-miss))))  ; Return 'write-miss

; Function to simulate reading from the cache
(define (read-from-cache address)
  (let ([set-index (address-to-set-index address)]
        [tag (address-to-tag address)])
    (if (and (hash-ref cache-valid-map (cons set-index 0) #f)  ; Check if the cache line is valid
             (= (hash-ref cache-tag-map (cons set-index 0) -1) tag))  ; Check if the tag matches
        'cache-hit  ; Return 'cache-hit if valid and tags match
        (begin  ; Cache miss handling
          (hash-set! cache-valid-map (cons set-index 0) #t)  ; Update the cache line to valid
          (hash-set! cache-tag-map (cons set-index 0) tag)  ; Update the tag
          'cache-miss))))  ; Return 'cache-miss



; Initialize the cache
(init-cache)

; Example operation to check the validity of a cache line
(define (is-valid? set-index way-index)
  (hash-ref cache-valid-map (cons set-index way-index) #f))

; Example operation to print cache state (for debugging purposes)
(define (print-cache-state)
  (for ([i (in-range kmax-cache-set-index)])
    (for ([w (in-range kmax-cache-way-index)])
      (printf "Set: ~a, Way: ~a, Valid: ~a, Tag: ~a\n"
              i w
              (is-valid? i w)
              (hash-ref cache-tag-map (cons i w) 0)))))

; Function to print the state of a cache line given an address
(define (print-cache-line-state address)
  (let* ([set-index (address-to-set-index address)]
         [tag (address-to-tag address)]
         [valid? (hash-ref cache-valid-map (cons set-index 0) #f)]
         [cached-tag (hash-ref cache-tag-map (cons set-index 0) -1)]
         [data (hash-ref cache-data-map (cons set-index 0) 'no-data)])
    (printf "Address: ~a\nSet Index: ~a\nTag: ~a (Expected: ~a)\nValid: ~a\nData: ~a\n"
            address set-index cached-tag tag valid? data)))



; Example usage
; Call the print function to display the initial cache state
(print-cache-state)

; Example write
(define example-address 1024)
(define example-data "example-data")
(define result-write (write-to-cache example-address example-data))
(printf "Writing to address ~a resulted in a ~a\n" example-address result-write)

; Example read
(define result-read (read-from-cache example-address))
(printf "Reading from address ~a resulted in a ~a\n" example-address result-read)

(print-cache-line-state example-address)


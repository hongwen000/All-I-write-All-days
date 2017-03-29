(define (repeated f n)
  (define (repeated-helper f n k h)
    (if (= n k)
      h
      (repeated-helper f n (+ 1 k) (compose f h))))
  (repeated-helper f n 1 f))


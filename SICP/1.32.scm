(define (accumulate combiner null-value term a next b)
  (if (> a b)
    null-value
    (combiner (term a)
       (accumulate term (next a) b))))
(define (accumulate-iter combiner null-value term a next b)
  (define (iter a result)
    (if (> a b)
      null-value
      (iter (next a) (combiner (result (term a)))))))
(define (sum term a next b)
  (accumulate-iter + 0 term a next b))
(define (product term a next b)
  (accumulate-iter * 1 term a next b))

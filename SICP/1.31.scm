(define (product term a next b)
  (if (> a b)
    0
    (* (term a)
       (product term (next a) b))))
(define (product-iter term a next b)
  (define (iter a result)
    (if (> a b)
      1
      (iter (next a) (result + (term a))))))

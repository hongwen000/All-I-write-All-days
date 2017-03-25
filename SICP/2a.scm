(define (square a) (* a a))
(define (sum term A next b)
  (if (> A B)
        0
        (+ (term A)
           (sum term
                (next a) 
                next b))))
(define (sum-int a b)
  (define (identity x) x)
  (sum identity a 1+ b))
(define (sum-sq a b)
  (sum square a 1+ b))
(define (pi-sum a b)
  (sum (lambda(i) 
         (/ 1.0 (* i (+ i 2.0))))
       a
       (lambda(i) (+ i 4.0))
       b))


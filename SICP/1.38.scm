(define (D-e i)
  (if (= 2 (modulo i 3))
    (* (/ (+ i 1) 3) 2)
    1))
(define (calc-e k)
  ( + (cont-frac-iter (lambda (i) 1.0) d-e k) 2)

    

(define (try avg-times real-power y)
  (let ((power (- real-power 1)))
    (fix-point ((repeated average-damp avg-times)
                       (lambda (x) (/ y
                                      (expt x power)))
                       )
             1.0
             )
  )
)
; power     1 2 3 4 5 6 7 8
; avg-times 0 1 1 2 2 2 2 3
; 2^        0 1 1 2 2 2 2 3
; log n / log 2 向下取整
(define (log-two-down real-power)
    (if (or (> real-power 2) (= real-power 2))
      (+ 1
         (log-two-down (/ real-power 2)))
    0))
(define (nth-sqrt real-power y)
  (try (log-two-down real-power) real-power y))


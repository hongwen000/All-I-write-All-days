#lang sicp
(define x (cons (list 1 2) (list 3 4)))

(define (count-leaves x)
  (cond ((null? x) 0)
        ((not (pair? x)) 1)
        (else (+ (count-leaves (car x))
                 (count-leaves (cdr x))))))

(define e2.25-1 (list 1 3 (list 5 7) 9))
;(car (cdr (car (cdr (cdr e2.25-1)))))

(define e2.25-2 (list (list 7)))
;(car (car e2.25-2))

(define e2.25-3 (list 1 (list 2 (list 3 (list 4 (list 5 (list 6 7)))))))
;一开始，最外层的表有三个元素：1，一个表，一个nil
;cdr 之后，还有两个元素：一个表，一个nil
;(car (cdr (car (cdr (car (cdr (car (cdr (car (cdr (car (cdr e2.25-3))))))))))))
#lang sicp

(define Y-wrong
  (lambda (f)
      ((lambda (x)
         (f (x x)))
       (lambda (x)
         (f (x x))))))

(define Y
  (lambda (f)
      ((lambda (x)
         (f (lambda (y) ((x x) y))))
       (lambda (x)
         (f (lambda (y) ((x x) y)))))))
(define f
  (lambda (func)
      (lambda (n)
        (if (= 0 n)
            1
            (* n(func (- n 1)))))))
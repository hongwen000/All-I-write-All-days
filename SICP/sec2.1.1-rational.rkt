#lang sicp
(define (gcd x y)
  (if (= 0 (modulo x y))
      y
      (gcd y (modulo x y))))
(define (make-rat n d)
  (cond ((and (< n 0) (< d 0)) (cons (- n) (- d)))
        ((and (> n 0) (< d 0)) (cons (- n) (- d)))
        (else (cons n d))))
(define (numer x)
  (let ((g (gcd (car x) (cdr x))))
    (/ (car x) g)))
(define (denom x)
  (let ((g (gcd (car x) (cdr x))))
    (/ (cdr x) g)))
(define (print-rat x)
  (newline)
  (display (numer x))
  (display "/")
  (display (denom x)))
(define (binop-rat x y op1 op2)
  (make-rat (op1 (op2 (numer x) (denom y))
                 (op2 (numer y) (denom x)))
            (op2 (denom x) (denom y))))
(define (add-rat x y)
  (binop-rat x y + *))
(define (sub-rat x y)
  (binop-rat x y - *))
(define (mul-rat x y)
  (make-rat (* (numer x) (numer y))
            (* (denom x) (denom y))))
(define (div-rat x y)
  (make-rat (* (numer x) (denom y))
            (* (denom x) (numer y))))
(define (equal-rat? x y)
  (= (* (numer x) (denom y))
     (* (numer y) (denom x))))
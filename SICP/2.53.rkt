#lang sicp
(#%require (only racket/base error))
(define (memq item x)
  (cond ((null? x) false)
        ((eq? item (car x)) x)
        (else (memq item (cdr x)))))
; (list 'a 'b 'c)
;; ('a 'b 'c)
; (list (list 'george))
;; (('george))
; (cdr '((x1 x2) (y1 y2)))
;; ((y1 y2))
; (cadr '((x1 x2) (y1 y2)))
;; (y1 y2)
; (pair? (car '(a short list)))
;; #f
; (memq 'red '((red shoes) (blue socks)))
;; #f
; (memq 'red '(red shoes blue socks))
;; '(red shoes blue socks)

;; 2.54
(define (equal? lst1 lst2) 
  (cond ((and (symbol? lst1) (symbol? lst2))
         (eq? lst1 lst2))
        ((and (null? lst1) (null? lst2))
         #t)
        ((or (null? lst1) (null? lst2))
         #f)
        ((and(eq? (car lst1) (car lst2))     ; 对比 car 部分
            (equal? (cdr lst1) (cdr lst2))))
        (else #f)))   ; 递归对比 cdr 部分
;; 2.55
;; 符号 ' 会被表示为quote(引号)

(define (deriv exp var)
  (cond ((number? exp) 0)
        ((variable? exp)
         (if (same-variable? exp var) 1 0))
        ((sum? exp)
         (make-sum (deriv (addend exp) var)
                   (deriv (augend exp) var)))
        ((product? exp)
         (make-sum
           (make-product (multiplier exp)
                         (deriv (multiplicand exp) var))
           (make-product (deriv (multiplier exp) var)
                         (multiplicand exp))))
        (else
         (error "unknown expression type -- DERIV" exp))))

(define (variable? x) (symbol? x))

(define (same-variable? v1 v2)
  (and (variable? v1) (variable? v2) (eq? v1 v2)))


(define (sum? x)
  (and (pair? x) (eq? (car x) '+)))

(define (addend s) (cadr s))

(define (augend s) (caddr s))

(define (product? x)
  (and (pair? x) (eq? (car x) '*)))

(define (multiplier p) (cadr p))

(define (multiplicand p) (caddr p))

(define (make-sum a1 a2)
  (cond ((=number? a1 0) a2)
        ((=number? a2 0) a1)
        ((and (number? a1) (number? a2)) (+ a1 a2))
        (else (list '+ a1 a2))))

(define (=number? exp num)
  (and (number? exp) (= exp num)))

(define (make-product m1 m2)
  (cond ((or (=number? m1 0) (=number? m2 0)) 0)
        ((=number? m1 1) m2)
        ((=number? m2 1) m1)
        ((and (number? m1) (number? m2)) (* m1 m2))
        (else (list '* m1 m2))))

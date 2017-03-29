#lang sicp
(#%require (only racket/base error))
(define (make-interval a b) (cons a b))

(define (lower-bound z) (car z))

(define (upper-bound z) (cdr z))

(define (add-interval x y)
  (make-interval (+ (lower-bound x) (lower-bound y))
                 (+ (upper-bound x) (upper-bound y))))

(define (sub-interval x y)
  (make-interval (- (lower-bound x) (upper-bound y))
                 (- (upper-bound x) (lower-bound y))))

(define (mul-interval x y)
  (let ((p1 (* (lower-bound x) (lower-bound y)))
        (p2 (* (lower-bound x) (upper-bound y)))
        (p3 (* (upper-bound x) (lower-bound y)))
        (p4 (* (upper-bound x) (upper-bound y))))
    (make-interval (min p1 p2 p3 p4)
                   (max p1 p2 p3 p4))))

(define (div-interval x y)
  (if (> (* (lower-bound y) (upper-bound y)) 0)
  (mul-interval x 
                (make-interval (/ 1.0 (upper-bound y))
                               (/ 1.0 (lower-bound y))))
  (error "Division by an interval spanning zero" y)))


(define (width-interval z)
  (- (upper-bound z)
     (lower-bound z)))

; width(add) = -(width(((lower-bound x) + (lower-bound y)) - ((upper-bound x) + (upper-bound y))) = width(interval1) + width(interval2)
; width(sub) = width(((lower-bound x) - (lower-bound y)) - ((upper-bound x) - (upper-bound y)) = width(interval1) + width(interval2)

;2.11 What question described in every situation, only two multiply operations are needed
;...is maybe wrong. When both interval spans zero.
;In other cases, classify by if an interval is postive, spans zero or negetive

(define (make-center-width c w)
  (make-interval (- c w) (+ c w)))

(define (center i)
  (/ (+ (lower-bound i) (upper-bound i)) 2))

(define (width i)
  (/ (- (upper-bound i) (lower-bound i)) 2))

(define (make-center-percent c p)
  (let ((w (* c p)))
    (make-center-width c w)))

;2.13 (*) = c1*c2 - (p1 + p2)c1*c2 + p1*p2*c1*c2
;the third term is a higer oder infinitesimal, just ignore it
;so the answer is (p1 + p2)

(define (par1 r1 r2)
  (div-interval (mul-interval r1 r2)
                (add-interval r1 r2)))

(define (par2 r1 r2)
  (let ((one (make-interval 1 1))) 
    (div-interval one
                  (add-interval (div-interval one r1)
                                (div-interval one r2)))))
;2.14 This is we didn't properly defined A/A ... should it be 1 or using the mul-interval op to find it non-one?

;2.15 Yes, pair2 would'nt introduce A/A

;2.16 Need the study of interval arithmetic
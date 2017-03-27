#lang sicp
;(#%require "sec2.1.1-rational.rkt")
(define (make-point x y)
  (cons x y))
(define (x-point p)
  (car p))
(define (y-point p)
  (cdr p))
(define (make-segment start end)
  (cons start end))
(define (start-segment segment)
  (car segment))
(define (end-segment segment)
  (cdr segment))
(define (midpoint-segment segment)
  (let ((mid-x (/ (+ (x-point (start-segment segment))
                     (x-point (end-segment segment)))
                  2))
        (mid-y (/ (+ (y-point (start-segment segment))
                     (y-point (end-segment segment)))
                  2)))
    (make-point mid-x mid-y)))
(define (print-point p)
  (newline)
  (display "(")
  (display (x-point p))
  (display ",")
  (display (y-point p))
  (display ")"))
;exericse 2.3.rkt
(define (make-rectangle left-top right-down)
  (cons left-top right-down))

(define (left-top-rect rectangle)
  (car rectangle))

(define (right-down-rect rectangle)
  (cdr rectangle))


(define (length-rect op rectangle)
  (let ((left-top (left-top-rect rectangle))
        (right-down (right-down-rect rectangle)))
    (abs (- (op left-top)
            (op right-down)))))

(define (width-rect rectangle)
  (length-rect x-point rectangle))

(define (height-rect rectangle)
  (length-rect y-point rectangle))

(define (left-down-rect rectangle)
  (let ((left-top (left-top-rect rectangle)))
    (make-point (x-point left-top)
                (- (y-point left-top)
                   (height-rect rectangle)))))

(define (right-up-rect rectangle)
  (let ((right-down (right-down-rect rectangle)))
    (make-point (x-point right-down)
                (+ (y-point right-down)
                   (height-rect rectangle)))))

(define (perimeter-rect rectangle)
  (* 2
     (+ (width-rect rectangle)
        (height-rect rectangle))))

(define (area-rect rectangle)
   (* (width-rect rectangle)
      (height-rect rectangle)))

#|
> (define p1 (make-point (- 1) 1))
> (define p2 (make-point 1 (- 1)))
> (define rect (make-rectangle p1 p2))
> rect
(mcons (mcons -1 1) (mcons 1 -1))
> (width-rect rect)
2
> (height-rect rect)
2
> (perimeter-rect rect)
8
> (area-rect rect)
4
>
|#
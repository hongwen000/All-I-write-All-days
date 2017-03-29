#lang sicp

(define (deep-reverse x)
  (reverse (map (lambda (x)
                  (if (pair? x)
                    (deep-reverse x)
                    x))
                x)))

(define (fringe x)
  (cond ((pair? x) (append (fringe (car x))
                           (fringe (cdr x))))
        ((null? x) '())
        (else (list x))))

;2.29
(define (make-mobile left right)
  (list left right))

(define (make-branch length structure)
  (list length structure))

;a)
(define (left-branch mobile)
    (car mobile))

(define (right-branch mobile)
    (cadr mobile))

(define (branch-length branch)
    (car branch))

(define (branch-structure branch)
    (cadr branch))
;b)
(define (total-weight x)
  (define (is-mobile x)
    (and (pair? (car x)) (pair? (cadr x))))
  (define (is-structure x)
    (and (not (pair? (car x))) (pair? (cadr x))))
  (define (is-leaf x)
    (and (not (pair? (car x))) (not (pair? (cadr x)))))
  (cond ((is-mobile x) (+ (total-weight (car x))
                          (total-weight (cadr x))))
        ((is-leaf x) (cadr x))
        ((is-structure x) (total-weight (cadr x)))
        (else (cdr x))))
;c)
(define (is-balance x)
  (= (total-weight (car x))
     (total-weight (cadr x))))

;2.32
(define (powerset s)
  (if (null? s)
      (list nil)
      (let ((rest (powerset (cdr s))))
        (append rest (map (lambda (x)
                            (cons (car s) x)) rest)))))
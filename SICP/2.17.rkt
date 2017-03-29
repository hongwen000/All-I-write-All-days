#lang sicp
;;;SECTION 2.2.1

;: (cons 1
;:       (cons 2
;:             (cons 3
;:                   (cons 4 nil))))


;: (define one-through-four (list 1 2 3 4))
;: 
;: one-through-four
;: (car one-through-four)
;: (cdr one-through-four)
;: (car (cdr one-through-four))
;: (cons 10 one-through-four)

(define (list-ref items n)
  (if (= n 0)
      (car items)
      (list-ref (cdr items) (- n 1))))

;: (define squares (list 1 4 9 16 25))

;: (list-ref squares 3)

(define (length-recv items)
  (if (null? items)
      0
      (+ 1 (length (cdr items)))))

;: (define odds (list 1 3 5 7))

;: (length odds)

(define (length items)
  (define (length-iter-helper a count)
    (if (null? a)
        count
        (length-iter-helper (cdr a) (+ 1 count))))
  (length-iter-helper items 0))

;: (append squares odds)
;: (append odds squares)


(define (append list1 list2)
  (if (null? list1)
      list2
      (cons (car list1) (append (cdr list1) list2))))

(define (last-pair list)
  (if (null? (cdr list))
      (car list)
      (last-pair (cdr list))))

(define (reverse list)
  (if (null? (cdr list))
      (cons (car list) nil)
      (append (reverse (cdr list)) (cons (car list) nil))))


;2.18

;; Counting change

(define (count-change amount)
  (cc amount 5))

(define (cc amount kinds-of-coins)
  (cond ((= amount 0) 1)
        ((or (< amount 0) (= kinds-of-coins 0)) 0)
        (else (+ (cc amount
                     (- kinds-of-coins 1))
                 (cc (- amount
                        (first-denomination kinds-of-coins))
                     kinds-of-coins)))))

(define (first-denomination kinds-of-coins)
  (cond ((= kinds-of-coins 1) 1)
        ((= kinds-of-coins 2) 5)
        ((= kinds-of-coins 3) 10)
        ((= kinds-of-coins 4) 25)
        ((= kinds-of-coins 5) 50)))

;: (count-change 100)

(define us-coins (list 50 25 10 5 1))

(define uk-coins (list 100 50 20 10 5 2 1 0.5))

;: (cc 100 us-coins)
(define (no-more? coin-values)
  (null? coin-values))

(define (except-first-denomination coin-values)
  (cdr coin-values))

(define (first-denomination-new coin-values)
  (car coin-values))

(define (cc-new amount coin-values)
  (cond ((= amount 0) 1)
        ((or (< amount 0) (no-more? coin-values)) 0)
        (else
         (+ (cc-new amount
                (except-first-denomination coin-values))
            (cc-new (- amount
                   (first-denomination-new coin-values))
                coin-values)))))

;2.20
(define (square x) (* x x))

(define (smallest-divisor n)
  (find-divisor n 2))

(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divides? test-divisor n) test-divisor)
        (else (find-divisor n (+ test-divisor 1)))))

(define (divides? a b)
  (= (remainder b a) 0))

(define (prime? n)
  (= n (smallest-divisor n)))

#|
(define (same-parity x . rest)
  (if (null? rest)
      nil
      (if (> (car rest) 0)
          (append (cons (car rest) nil) (same-parity x . (cdr rest)))
          (append (cons nil nil) (same-parity x (cdr rest))))))
|#
;I failed to work out this question ... it can be find that it's impossible to recurisively call ITSELF
;solution is define another helper function

(define (is-even? x)
  (= (modulo x) 0))
(define (same-parity x . rest)
  (define (helper x list)
    (cond ((null? x list) nil)
          ((= (is-even? x) (is-even? (car list))) (append (cons (car rest) nil) (helper x (cdr rest))))
          (else (append (cons nil nil) (helper x (cdr rest))))))
  (helper x (cons x rest)))
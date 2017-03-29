#lang sicp
(define (accumulate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumulate op initial (cdr sequence)))))
;2.33

(define (map p sequence)
  (accumulate (lambda (x y) (cons (p x) y))
              nil
              sequence))

(define (append seq1 seq2)
  (accumulate cons seq2 seq1))

(define (length seq)
  (accumulate (lambda (x y) (+ 1 y)) 0 seq))
;2.34

(define (horner-eval x coefficient-sequence)
  (accumulate (lambda (this-coeff higher-terms) (+ this-coeff
                                                   (* x higher-terms)))
              0
              coefficient-sequence))

(define (count-leaves t)
  (accumulate + 0 (map (lambda(x) (cond ((pair? x) (count-leaves x))
                                        (else 1)))
                       t)))

(define (accumulate-each op init seqs)
  (if (null? seqs)
             nil
             (cons (accumulate op init (car seqs))
                   (accumulate-each op init (cdr seqs)))))

(define s (list (list 1 2 3) (list 4 5 6) (list 7 8 9) (list 10 11 12)))

;2.36
(define (accumulate-n op init seqs)
  (if (null? seqs)
             nil
             (cons (accumulate op init (map (lambda (x) (if (null? x) nil (car x)))
                                            seqs))
                   (accumulate-n op init ((lambda (x) (if (null? (cdar x))
                                                         nil
                                                         (map cdr x)))
                                           seqs)))))

;2.38
(define (fold-left op initial sequence)
  (define (iter result rest)
    (if (null? rest)
        result
        (iter (op result (car rest))
              (cdr rest))))
  (iter initial sequence))
(define fold-right accumulate)
(define (reverse seq)
  (fold-right (lambda (x y) (append y (cons x '()))) nil seq))
(define (reverse-2 seq)
  (fold-left (lambda (x y) (append x (cons y '()))) nil seq))

;2.40
(define (square n) (* n n))
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

(define (enumerate-interval x y)
  (if (> x y)
    nil
    (cons x (enumerate-interval (+ 1 x) y))))
(define (nested-mapping n)
  (accumulate append
              nil
              (map (lambda (i)
                     (map (lambda (j)
                            (list i j))
                          (enumerate-interval 1 (- i 1))))
                   (enumerate-interval 1 n))))
(define (flatmap proc seq)
  (accumulate append nil (map proc seq)))
(define (prime-sum? pair)
  (prime? (+ (car pair) (cadr pair))))
(define (make-pair-sum pair)
  (list (car pair) (cadr pair) (+ (car pair) (cadr pair))))
(define (prime-sum-pairs n)
  (map make-pair-sum
       (filter prime-sum?
               (flatmap
                 (lambda (i)
                   (map (lambda (j) (list i j))
                        (enumerate-interval 1 (- i 1))))
                 (enumerate-interval 1 n))))) 


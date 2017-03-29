#lang sicp
(define (square x) (* x x))

(define (map-recv proc items)
  (if (null? items)
      nil
      (cons (proc (car items))
            (map proc (cdr items)))))

(define (square-list items)
  (define (iter things answer)
    (if (null? things)
        answer
        (iter (cdr things)
              (append answer
                      (cons (square (car things)) nil)))))
  (iter items nil))
;对两个表进行接续应该使用append
(define (map proc items)
(define (map-iter proc items answer)
  (if (null? items)
      answer
      (map-iter proc
                (cdr items)
                (append answer
                        (cons (proc (car items)) nil)))))
  (map-iter proc items nil))


(define (for-each proc items)
  (if (not (null? (cdr items)))
      ((proc (car items))
      (for-each proc (cdr items))) ;这里问题是 (for-each proc (cdr items))被当作参数给(proc (car items))
      (proc (car items))))         ;应用了所以要么用特殊形式的带begin的if，要么用cond（默认带begin)
                                   ;要不让if体内只有一个语句
 (define (for-each-web proc items)  
     (proc (car items)) 
     (if (not (null? (cdr items))) 
         (for-each-web proc (cdr items)) 
         true
         )) 
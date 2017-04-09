(define (filipped-pairs painter)
  (let ((painter2 (beside painter (filp-vert painter))))
    (below painter2 painter2)))

(define (right-split painter n)
  (if (= n 0)
    painter
    (let ((smaller (right-split painter (- n 1))))
      (beside painter (below smaller smaller)))))

(define (corner-split painter n)
  (if (= n 0)
    painter
    (let ((up (up-split painter (- n 1)))
          (right (right-split painter (- n 1))))
      (let ((top-left (beside up up))
            (bottom-right (below right right))
            (corner (corner-split painter (- n 1))))
        (beside (below painter top-left)
                (below bottom-right corner))))))
;2.44
(define (up-split painter n)
  (if (= n 0)
    painter
    (let ((smaller (up-split painter (- n 1))))
      (below painter (beside smaller smaller)))))

;2.45
(define (split op1 op2)
  (lambda (painter n)
    (if (= n 0)
     painter
     (let ((smaller ((split op1 op2) painter (- n 1))))
       (op1 painter (op2 smaller smaller))))))
(define (square-limit painter n)
  (let ((quarter (coner-split painter n)))
    (let ((half (beside (flip-split painter n) quarter)))
      (below (flip-vert half) half))))

(define (square-of-four t1 tr bl br)
  (lambda (painter)
    (let ((top (beside (tl painter) (tr painter)))
          (bottom (beside (bl painter) (br painter))))
      (below bottom top))))

(define (frame-coord-map frame)
  (lambda (v)
    (add-vect 


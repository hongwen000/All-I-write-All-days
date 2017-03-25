(define (filtered-accumulate-iter filt combiner null-value term a next b)
  (define (iter a result)
    (define (helper realresult)
      (iter (next a) realresult))
    (if (a > b) ; no writing   [if [filt a b]]  [a,b] declares an interval
      null-value
      (if (filt a)
      (helper (combiner (result (term a))))
      (helper result)))))

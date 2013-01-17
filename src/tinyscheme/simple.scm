; simple.scm

(define sqr
	(lambda (x)
		(* x x)))

(define seq
	(lambda (a b)
		(if (<= a b)
			(cons a (seq (+ 1 a) b))
			'())))

(hello_world)
(display "Hello World from TinyScheme\n")

(display "sqr(9)=")
(display (test-sqr 9))
(display "\n")

(display "sqr(9)=")
(display (sqr 9))
(display "\n")

(display "sum=")
(display (test-sum 1 2 3 4 5 6))
(display "\n")

(display "sum=")
(display (apply + (seq 1 6)))
(display "\n")

(display "sum=")
(display (+ 1 2 3 4 5 6))
(display "\n")

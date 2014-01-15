(defun is_dividable (dividee divider)
  (eq (mod dividee divider) 0))

(defun is_fizz (num)
  (is_dividable num 3))
(defun is_buzz (num)
  (is_dividable num 5))

(defun fizzbuzz (min max)
  (if (<= min max)
      (progn
	(cond ((and (is_fizz min) (is_buzz min))
	       (format t "FizzBuzz~%"))
	      ((is_fizz min)
	       (format t "Fizz~%"))
	      ((is_buzz min)
	       (format t "Buzz~%"))
	      (t
	       (format t "~A~%" min)))
	(fizzbuzz (+ min 1) max))))

(fizzbuzz 1 100)

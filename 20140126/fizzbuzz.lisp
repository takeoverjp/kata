(defun is_fizz (num)
  (eq (mod num 3) 0))

(defun is_buzz (num)
  (eq (mod num 5) 0))

(defun fizzbuzz (min max)
  (if (<= min max)
      (progn
        (cond ((and (is_fizz min) (is_buzz min))
               (format t "FizzBuzz~%"))
              ((is_fizz min)
               (format t "Fizz~%"))
              ((is_buzz min)
               (format t "Fizz~%"))
              (t
               (format t "~A~%" min)))
        (fizzbuzz (1+ min) max))))

(fizzbuzz 1 100)


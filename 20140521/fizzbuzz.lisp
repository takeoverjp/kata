(defun fizzbuzz (min max)
  (if (<= min max)
      (progn
        (cond
         ((eq (mod min 15) 0) (format t "FizzBuzz~%"))
         ((eq (mod min 3) 0)  (format t "Fizz~%"))
         ((eq (mod min 5) 0)  (format t "Buzz~%"))
         (t (format t "~A~%" min)))
        (fizzbuzz (+ 1 min) max))
    ))

(fizzbuzz 1 100)
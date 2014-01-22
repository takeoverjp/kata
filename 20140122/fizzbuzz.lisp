(defun is_dividable (dividee divider)
  (eq (mod dividee divider) 0))

(defun is_fizz (num)
  (is_dividable num 3))

(defun is_buzz (num)
  (is_dividable num 5))

(defun fizzbuzz_in (num)
  (cond ((and (is_fizz num) (is_buzz num))
         (format t "FizzBuzz~&"))
        ((is_fizz num)
         (format t "Fizz~&"))
        ((is_buzz num)
         (format t "Buzz~&"))
        (t
         (format t "~A~&" num))))

(defun fizzbuzz (min max)
  (if (<= min max)
      (progn
        (fizzbuzz_in min)
        (fizzbuzz (1+ min) max))))

(fizzbuzz 1 100)

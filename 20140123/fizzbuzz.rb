def is_fizz num
    return (num % 3) == 0
end

def is_buzz num
  return (num % 5) == 0
end

def fizzbuzz num
  if is_buzz num and is_fizz num
    p "FizzBuzz"
  elsif is_fizz num
    p "Fizz"
  elsif is_buzz num
    p "Buzz"
  else
    p num
  end
end

for i in 1..100
  fizzbuzz i
end

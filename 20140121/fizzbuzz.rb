def is_dividable(dividee, divider)
    return (dividee % divider == 0)
end

def is_fizz(num)
    return is_dividable(num, 3)
end

def is_buzz(num)
    return is_dividable(num, 5)
end

def fizzbuzz(num)
    if is_fizz(num) and is_buzz(num)
      return "FizzBuzz"
    elsif is_fizz(num)
      return "Fizz"
    elsif is_buzz(num)
      return "Buzz"
    else
      return num
    end
end

for i in 1..100
    p fizzbuzz i
end
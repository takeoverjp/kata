def toStr(num)
  if (num % 15 == 0)
    return 'FizzBuzz'
  elsif (num % 3 == 0)
    return 'Fizz'
  elsif (num % 5 == 0)
    return 'Buzz'
  else
    return num
  end
end

def fizzBuzz(min, max)
  for i in (min..max)
    p toStr(i)
  end
end

fizzBuzz(1, 100)

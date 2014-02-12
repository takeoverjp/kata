def toStr i
  if i % 15 == 0
    "FizzBuzz"
  elsif i % 3 == 0
    "Fizz"
  elsif i % 5 == 0
    "Buzz"
  else
    i.to_s
  end
end

def fizzBuzz array
  array.map{|i| toStr i}
end

puts fizzBuzz (1..100)

def toStr(num)
  if (num % 15 == 0)
    return "FizzBuzz"
  elsif (num % 3 == 0)
    return "Fizz"
  elsif (num % 5 == 0)
    return "Buzz"
  else
    return num
  end
end

def fizzBuzz(min,max)
  (min..max).map{|i|
    puts toStr(i)
  }
end

def printUsage()
  puts "[USAGE] ruby20 fizzbuzz.rb min max"
end

if (ARGV.length != 2)
  printUsage
  exit
end

fizzBuzz(ARGV[0].to_i,ARGV[1].to_i)

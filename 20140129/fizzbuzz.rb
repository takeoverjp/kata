class FizzBuzz
  def initialize(min, max)
      print "hoge"
    @min = min
    @max = max
  end

  def fizz? num
    return num % 3 == 0
  end

  def buzz? num
    return num % 5 == 0
  end

  def fizzbuzz num
    if fizz?(num) and buzz?(num)
      p "FizzBuzz"
    elsif fizz?(num)
      p "Fizz"
    elsif buzz?(num)
      p "Buzz"
    else
      p num
    end
  end

  def run
    for i in @min..@max
      fizzbuzz i
    end
  end
end

fb = FizzBuzz.new(1, 100)
fb.run

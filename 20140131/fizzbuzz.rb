class FizzBuzz
  def initialize(min,max)
    @min = min
    @max = max
  end

  def fizz? num
    num % 3 == 0
  end
  def buzz? num
    num % 5 == 0
  end
  private :fizz?,:buzz?

  def fizzbuzz num
    if fizz? num and buzz? num
      "FizzBuzz"
    elsif fizz? num
      "Fizz"
    elsif buzz? num
      "Buzz"
    else
      num.to_s
    end
  end
  private :fizzbuzz

  def run
    (@min..@max).map{|i| puts fizzbuzz i}
  end
end

FizzBuzz.new(1,100).run


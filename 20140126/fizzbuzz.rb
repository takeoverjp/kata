class FizzBuzz
  def initialize(min, max)
    @min = min
    @max = max
  end

  def run
    for num in @min..@max
      fizzbuzz num
    end
  end

  def fizz? num
    return num % 3 == 0
  end
  private :fizz?

  def buzz? num
    return num % 5 == 0
  end
  private :buzz?

  def fizzbuzz num
    if fizz? num and buzz? num
      p "FizzBuzz"
    elsif fizz? num
      p "Fizz"
    elsif buzz? num
      p "Buzz"
    else
      p num
    end
  end
  private :fizzbuzz
end

fb = FizzBuzz.new(1, 100)
fb.run


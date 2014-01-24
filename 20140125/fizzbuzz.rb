class FizzBuzz
  def initialize(min, max)
    @min = min
    @max = max
  end

  def fizz? num
    return (num % 3) == 0
  end
  private :fizz?

  def buzz? num
    return (num % 5) == 0
  end
  private :buzz?

  def run
    for i in @min..@max
      if fizz? i and buzz? i
        p "FizzBuzz"
      elsif fizz? i
        p "Fizz"
      elsif buzz? i
        p "Buzz"
      else
        p i
      end
    end
  end
end

fb = FizzBuzz.new(1, 100)
fb.run

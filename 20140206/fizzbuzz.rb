class FizzBuzz
  def initialize min, max
    @min = min
    @max = max
  end

  def fizz? i
    i % 3 == 0
  end
  private :fizz?

  def buzz? i
    i % 5 == 0
  end
  private :buzz?

  def fizzbuzz? i
    s = ""
    s += "Fizz" if fizz? i
    s += "Buzz" if buzz? i
    s += i.to_s if s==""
    return s
  end
  private :fizzbuzz?

  def run
    for i in @min..@max
      puts fizzbuzz? i
    end
  end
end

FizzBuzz.new(1, 100).run

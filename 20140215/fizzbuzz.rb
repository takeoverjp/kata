class FizzBuzz
  def initialize min,max
    @min = min
    @max = max
  end

  def run
    for i in @min..@max
      s = ''
      s += 'Fizz' if i % 3 == 0
      s += 'Buzz' if i % 5 == 0
      s += i.to_s if s == ''
      puts s
    end
  end
end

FizzBuzz.new(1,100).run

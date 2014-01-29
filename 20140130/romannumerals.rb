class RomanNumerals
  attr_reader :rom

  def initialize num
    @num = num
    @rom = toRoman(@num)
  end

  def toRomanDigit(num, ten, five, one)
    if num >= 10 or num < 0
      raise ArgumentError, "Too large"
    elsif num == 9
      return one + ten
    elsif num >= 5
      return five + one * (num % 5)
    elsif num >= 4
      return one * (5 - num) + five
    elsif num >= 0
      return one * num
    else
      raise ArgumentError, "Too small"
    end
  end

  def toRoman num
    thous = num / 1000
    hunds = (num % 1000) / 100
    tens = (num % 100) / 10
    ones = num % 10
    if thous > 4
      raise ArgumentError, "Too large"
    end
    return toRomanDigit(thous, "", "", "M") +
      toRomanDigit(hunds, "M", "D", "C") +
      toRomanDigit(tens, "C", "L", "X") +
      toRomanDigit(ones, "X", "V", "I")
  end

  def inspect
    return @num.inspect + " -> " + @rom
  end
end

rom = RomanNumerals.new(1)
p rom
rom = RomanNumerals.new(4)
p rom
rom = RomanNumerals.new(8)
p rom
rom = RomanNumerals.new(13)
p rom
rom = RomanNumerals.new(24)
p rom
rom = RomanNumerals.new(369)
p rom
rom = RomanNumerals.new(448)
p rom
rom = RomanNumerals.new(1998)
p rom
rom = RomanNumerals.new(2751)
p rom


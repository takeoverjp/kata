
def is_fizz(num)
    if num % 3 == 0
        return true
    else
	return false
    end
end

def is_buzz(num)
    if num % 5 == 0
        return true
    else
	return false
    end
end

for i in 1..100
    if (is_fizz(i) and is_buzz(i)) then
        p "FizzBuzz"
    elsif is_fizz(i) then
        p "Fizz"
    elsif is_buzz(i) then
        p "Buzz"
    else
        p i
    end
end
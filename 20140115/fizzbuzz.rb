def is_dividable(dividee, divider)
    dividee % divider == 0
end

def is_fizz(num)
    is_dividable(num, 3)
end

def is_buzz(num)
    is_dividable(num, 5)
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
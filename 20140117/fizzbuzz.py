def is_dividable(dividee, divider):
    return dividee % divider == 0

def is_fizz(num):
    return is_dividable(num, 3)

def is_buzz(num):
    return is_dividable(num, 5)

def fizzbuzz(num):
    if (is_fizz(i) and is_buzz(i)):
        return "FizzBuzz"
    elif (is_fizz(i)):
        return "Fizz"
    elif (is_buzz(i)):
        return "Buzz"
    else:
        return i

for i in range(1, 101):
    print fizzbuzz(i)

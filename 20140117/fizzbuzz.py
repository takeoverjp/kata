def is_dividable(dividee, divider):
    return dividee % divider == 0

def is_fizz(num):
    return is_dividable(num, 3)

def is_buzz(num):
    return is_dividable(num, 5)

def fizzbuzz(num):
    if (is_fizz(num) and is_buzz(num)):
        return "FizzBuzz"
    elif (is_fizz(num)):
        return "Fizz"
    elif (is_buzz(num)):
        return "Buzz"
    else:
        return num

if __name__ == '__main__':
    for i in range(1, 101):
        print fizzbuzz(i)

def to_str(num):
    if num % 15 == 0:
        return "FizzBuzz"
    elif num % 3 == 0:
        return "Fizz"
    elif num % 5 == 0:
        return "Buzz"
    else:
        return str(num)

def fizzbuzz(array):
    for i in array:
        print(to_str(i))

fizzbuzz(range(1,100))


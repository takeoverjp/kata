def to_str(num):
    if num % 15 == 0:
        return "FizzBuzz"
    elif num % 3 == 0:
        return "Fizz"
    elif num % 5 == 0:
        return "Buzz"
    else:
        return num

def fizzbuzz(min,max):
    for i in range(min,max):
        print(to_str(i))

fizzbuzz(1,100)

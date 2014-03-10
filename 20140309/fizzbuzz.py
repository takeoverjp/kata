def toStr(i):
    if i % 15 == 0:
        return "FizzBuzz"
    elif i % 3 == 0:
        return "Fizz"
    elif i % 5 == 0:
        return "Buzz"
    else:
        return i


def fizzbuzz(min, max):
    for i in range(min, max):
        print(toStr(i))

fizzbuzz(1,100)

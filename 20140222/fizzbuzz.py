def toStr(i):
    if i % 15 == 0:
        return "FizzBuzz"
    elif i % 3 == 0:
        return "Fizz"
    elif i % 5 == 0:
        return "Buzz"
    else:
        return i

def fizzBuzz(array):
    for i in array:
        print(toStr(i))

fizzBuzz(range(1,100))

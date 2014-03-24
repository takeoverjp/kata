def toStr(num):
    if num % 15 == 0:
        return "FizzBuzz"
    elif num % 3 == 0:
        return "Fizz"
    elif num % 5 == 0:
        return "Buzz"
    else:
        return num

def FizzBuzz(min,max):
    for i in range(min,max):
        print(toStr(i))

FizzBuzz(1,100)

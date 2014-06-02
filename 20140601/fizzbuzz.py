def toStr(num):
    if (num % 15 == 0):
        return "FizzBuzz"
    elif (num % 3 == 0):
        return "Fizz"
    elif (num % 5 == 0):
        return "Buzz"
    else:
        return num

def fizzBuzz(min,max):
    for i in range(min,max+1):
        print(toStr(i))

fizzBuzz(1, 100)
    

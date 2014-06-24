def toStr(i):
    if i % 15 == 0:
        return "FizzBuzz"
    elif i % 3 == 0:
        return "Fizz"
    elif i % 5 == 0:
        return "Buzz"
    else:
        return i

def fizzBuzz(min,max):
    for i in range(min,max+1):
        print(toStr(i))
    
fizzBuzz(1,100)

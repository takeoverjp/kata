def fbstr(i):
    if i % 15 == 0:
        s = "FizzBuzz"
    elif i % 3 == 0:
        s = "Fizz"
    elif i % 5 == 0:
        s = "Buzz"
    else:
        s = str(i)
    return s

def fizzbuzz(array):
    for i in array:
        print(fbstr(i))

fizzbuzz(range(1,100))

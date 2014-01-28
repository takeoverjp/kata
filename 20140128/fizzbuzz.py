def is_fizz(num):
    return num % 3 == 0

def is_buzz(num):
    return num % 5 == 0

def fizzbuzz(num):
    if is_fizz(num) and is_buzz(num):
        print "FizzBuzz"
    elif is_fizz(num):
        print "Fizz"
    elif is_buzz(num):
        print "Buzz"
    else:
        print num

for i in range(1,100):
    fizzbuzz(i)
    

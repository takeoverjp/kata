function toStr(num){
  if (num % 15 == 0)
    return "FizzBuzz";
  else if (num % 3 == 0)
    return "Fizz";
  else if (num % 5 == 0)
    return "Buzz";
  else
    return num;
}

function fizzBuzz(min, max){
  for (var i = min; i <= max; i++) {
    print(toStr(i));
  }
}

fizzBuzz(1,100);
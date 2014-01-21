var console = {};
console.log = function (str){
  print(str);
};

function is_dividable(dividee, divider){
  return (dividee % divider == 0);
}
function is_fizz(num){
  return is_dividable(num, 3);
}

function is_buzz(num){
  return is_dividable(num, 5);
}

function fizzbuzz(num){
  if (is_fizz(num) && is_buzz(num))
    console.log("FizzBuzz");
  else if (is_fizz(num))
    console.log("Fizz");
  else if (is_buzz(num))
    console.log("Buzz");
  else
    console.log(num);
}

for (var i = 0; i < 100; i++){
  fizzbuzz(i+1);
}
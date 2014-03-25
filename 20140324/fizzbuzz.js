function toStr(i) {
    if (i % 15 == 0)
	return "FizzBuzz";
    else if (i % 3 == 0)
	return "Fizz";
    else if (i % 5 == 0)
	return "Buzz";
    else
	return i;
}

function fizzBuzz(min, max) {
    for (var i = min; i <= max; i++) {
	print(toStr(i));
    }
}

fizzBuzz(1, 100);
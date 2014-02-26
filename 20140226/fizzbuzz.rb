(1..100).map{|i|s='';i%3==0&&s+='Fizz';i%5==0&&s+='Buzz';s==''&&s=i;puts s}

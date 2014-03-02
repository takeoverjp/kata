(1..100).map{|i|s='';s='Fizz'if i%3==0;s+='Buzz'if i%5==0;s=i.to_s if s=='';puts s}

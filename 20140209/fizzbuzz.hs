
toStr :: Int -> String
toStr i = if (i `mod` 15) == 0 then "FizzBuzz"
      else if (i `mod` 3) == 0 then "Fizz"
      else if (i `mod` 5) == 0 then "Buzz"
      else show(i)

fizzBuzz :: [Int] -> [String]
fizzBuzz array = map toStr array

main :: IO ()
main = do
     print(fizzBuzz([1..100]))

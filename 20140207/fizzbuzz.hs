module Main where

toStr :: Int -> String
toStr n =
      if (n `mod` 15) == 0 then "FizzBuzz"
      else if (n `mod` 3) == 0 then "Fizz"
      else if (n `mod` 5) == 0 then "Buzz"
      else show n

fizzbuzz :: [Int] -> [String]
fizzbuzz a = map (toStr) a

main :: IO ()
main  = do
     print(fizzbuzz([1..100]))
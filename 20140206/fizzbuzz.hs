module Main (main) where

isFizz :: Int -> Bool
isFizz i =
    i `mod` 3 == 0

isBuzz :: Int -> Bool
isBuzz i =
    i `mod` 5 == 0

toStr :: Int -> String
toStr i =
      if (isFizz i) then
         if (isBuzz i) then
            "FizzBuzz"
         else
            "Fizz"
      else
        if (isBuzz i) then
           "Buzz"
        else
           show i

fizzbuzz :: Int -> [String]
fizzbuzz n = map toStr [1 .. n]

main :: IO ()
main = do
     print (fizzbuzz 100)
#!/usr/bin/ocaml

open Printf

let is_fizz t =
 (t mod 3) = 0;;

let is_buzz t =
 (t mod 5) = 0;;

let rec fizzbuzz min max =
 if min <= max then begin
  if is_fizz min && is_buzz min
   then printf "FizzBuzz\n"
  else if is_fizz min
   then printf "Fizz\n"
  else if is_buzz min
   then printf "Buzz\n"
  else
   printf "%d\n" min;
  fizzbuzz (min + 1) max
 end;;

fizzbuzz 1 100;;

#!/bin/sh
#set -x

is_fizz ()
{
    [ `expr $1 % 3` -eq 0 ]
}

is_buzz ()
{
    [ `expr $1 % 5` -eq 0 ]
}

fizzbuzz ()
{
    num=$1
    if is_fizz $num && is_buzz $num; then
        echo "FizzBuzz"
    elif is_fizz $num; then
        echo "Fizz"
    elif is_buzz $num; then
        echo "Buzz"
    else
        echo "$num"
    fi
}

for i in `seq 1 100`; do
    fizzbuzz $i
done

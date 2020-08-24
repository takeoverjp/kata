fizzbuzz: fizzbuzz.cpp
	g++ -o $@ $^ -g -W -Werror -std=c++11

run: fizzbuzz
	./$^

.PHONY: run clean

clean:
	rm -f *~ *.o

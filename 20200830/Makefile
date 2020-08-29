args: args.cpp
	g++ -g -Og -W -Wall -Werror -o $@ $^ -lgtest -lpthread -lgtest_main

clean:
	rm -f args *.o *~

test: args
	./$<

.PHONY: clean test

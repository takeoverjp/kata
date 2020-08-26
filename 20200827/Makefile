all: binchop test_virtual_destoructor

binchop: binchop.cpp
	g++ -g -Og -W -Wall -Werror -o $@ $^ -lgtest_main -lgtest -lpthread

test_virtual_destoructor: virtual_destoructor.cpp
	g++ -g -Og -W -Wall -Werror -o $@ $^

clean:
	rm -f binchop *.o *~

test: binchop
	./$<

.PHONY: clean test

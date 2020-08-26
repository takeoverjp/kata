binchop: binchop.cpp
	g++ -g -Og -W -Wall -Werror -o $@ $^ -lgtest_main -lgtest -lpthread

clean:
	rm -f binchop *.o *~

test: binchop
	./$<

.PHONY: clean test

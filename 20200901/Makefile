bowling: bowling.cpp
	g++ -g -Og -Wall -W -Werror -o $@ $^ -lgtest -lgtest_main -lpthread

test: bowling
	./$^

clean:
	rm -f bowling

.PHONY: test clean

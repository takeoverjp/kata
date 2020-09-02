bowling: bowling.cpp
	g++ -g -Og -W -Wall -Werror -o $@ $^ -lgtest_main -lgtest -lpthread

clean:
	rm -f bowling

test: bowling
	./$<

.PHONY: clean test

binchop: binchop.cpp
	g++ -g -Og -W -Wall -Wno-overflow -Werror -o $@ $^ -lgtest -lgtest_main -pthread

clean:
	rm -f *~ *.o binchop

test: binchop
	./$^

.PHONY: clean test

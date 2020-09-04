FileLogger: FileLogger.cpp
	g++ -W -Wall -Werror -g -Og -o $@ $^ -lgtest -lgtest_main -lpthread -lgmock -std=c++11

test: FileLogger
	./$^

clean:
	rm -f *~ *.o FileLogger

.PHONY: clean test

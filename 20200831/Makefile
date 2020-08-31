args: args.cpp
	g++ -Og -g -W -Wall -Werror -o $@ $^ -lgtest -lgtest_main -lpthread

clean:
	rm -f *~ args

test: args
	./args

.PHONY: clean test

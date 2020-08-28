CXXFLAGS=-g -Og -W -Wall -Werror
LDFLAGS=-lgtest -lpthread -lgtest_main

diamond: diamond.cpp
	g++ $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

test: diamond
	./diamond

clean:
	rm -f diamond

.PHONY: clean test

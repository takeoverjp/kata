all: func.sym func.asm func.lambda.sym func.lambda.asm

args: args.cpp
	g++ -g -Og -W -Wall -Werror -o $@ $^ -lgtest -lpthread -lgtest_main

func: func.cpp
	g++ -O0 -o $@ $^

func.lambda: func.cpp
	g++ -DUSE_LAMBDA -O0 -o $@ $^

func.sym: func
	readelf -sW func | c++filt > $@

func.asm: func
	objdump -Cd func > $@

func.lambda.sym: func.lambda
	readelf -sW func.lambda | c++filt > $@

func.lambda.asm: func.lambda
	objdump -Cd func.lambda > $@

clean:
	rm -f args func func.lambda *.sym *.asm *.o *~

test: args
	./$<

.PHONY: clean test

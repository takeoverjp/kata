zcore: zcore.c
	gcc -Og -g -W -Wall -Werror -o $@ $^ -lz

clean:
	rm -f zcore

test: zcore
	./test.sh

.PHONY: clean test

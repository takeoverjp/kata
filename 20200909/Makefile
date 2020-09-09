rotate: rotate.c
	gcc -W -Wall -Werror -g -Og -o $@ $^

test: rotate
	./test.sh

clean:
	rm rotate *~ *.o

.PHONY: clean test

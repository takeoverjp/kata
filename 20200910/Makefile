core_pipe: core_pipe.c
	gcc -W -Wall -Werror -g -Og -o $@ $^ -lz

test: core_pipe
	./test.sh

clean:
	rm core_pipe *~ *.o out

.PHONY: clean test

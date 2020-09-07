.PHONY: all clean
all: result.png

clean:
	rm -f eval_cache *~ *.png *.csv

eval_cache: eval_cache.c
	gcc -O0 -g -o $@ $^

result.csv: eval_cache
	./eval.sh | tee $@

result.png: result.csv
	./graph.py $^ $@

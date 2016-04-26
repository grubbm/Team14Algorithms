CFLAGS = -Wall -fpic -lm -std=c99 -w

all: greedy.c dpchange.c
	gcc -o program greedy.c $(CFLAGS)
	./program testing.txt
	gcc -o changedp changedp.c $(CFLAGS)
	./changedp
				
clean:
	rm -f program

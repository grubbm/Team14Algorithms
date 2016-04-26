CFLAGS = -Wall -fpic -lm -std=c99 -w

all: greedy.c
	gcc -o program greedy.c $(CFLAGS)
	./program testing.txt
				
clean:
	rm -f program

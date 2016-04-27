CFLAGS = -Wall -fpic -lm -std=c99 -w

all: greedy.c dpchange.c changeslow.c
	gcc -o greedy greedy.c $(CFLAGS)
	./greedy testing.txt
	gcc -o changedp changedp.c $(CFLAGS)
	./changedp
	gcc -o changeslow changeslow.c $(CFLAGS)
	./changeslow 4slow.txt			
clean:
	rm -f program

CC=gcc
CFLAGS=-Wall -Wextra

all: main

main: main.o adjacency-matrix.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f main *.o *.gch

CC=gcc
CFLAGS=-Wall -Wextra

all: main

main: main.o darray.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f main *.o *.gch

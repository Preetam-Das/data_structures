CC=gcc
CFLAGS=-Wall -Wextra

all: main

main: main.o linked_list.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f main *.o *.gch

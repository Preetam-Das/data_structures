CC=gcc
CFLAGS=-Wall -Wextra
SRCDIR=src
INCDIR=include
OBJDIR=obj
BINDIR=bin
SRC=$(wildcard $(SRCDIR)/*.c)
BIN=$(BINDIR)/main
OBJ=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(BIN)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

clean:
	rm -f $(BINDIR)/* $(OBJDIR)/*

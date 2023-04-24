CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -ldl

all: main

main: main.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f main
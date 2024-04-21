## Very simple makefile.
CC=gcc
CFLAGS=-g -O0 -Wall

main: ALL.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm main

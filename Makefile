CC = gcc

CFLAGS = -Wall -Werror -pedantic -O2 -g

.PHONY: all
all: main.c vtest.h
	$(CC) $(CFLAGS) -o main main.c

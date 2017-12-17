CC = gcc
CFLAGS = -Wall

build: main

main: main.o
	$(CC) main.o -o main

main.o: main.c 	bmp_header.h
	$(CC) $(CFLAGS) -c main.c 
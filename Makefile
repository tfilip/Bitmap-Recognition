CC = gcc
CFLAGS = -Wall

build: main

main: main.o input_output.o
	$(CC) main.o input_output.o -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c 

input_output.o: input_output.c input_output.h
	$(CC) -c input_output.c	

run:
	./main

clean:
	rm -rf .main.o input_output.o main
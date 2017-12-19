CC = gcc
CFLAGS = -Wall

build: main

main: main.o input_output.o numbers.o pixelwork.o
	$(CC) main.o input_output.o numbers.o pixelwork.o -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c 

numbers.o: numbers.c numbers.h
	$(CC) $(CFLAGS) -c numbers.c

input_output.o: input_output.c input_output.h
	$(CC) $(CFLAGS) -c input_output.c	

pixelwork.o: pixelwork.c pixelwork.h
	$(CC) $(CFLAGS) -c pixelwork.c
run:
	./main

clean:
	rm -rf .main.o input_output.o main
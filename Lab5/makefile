# makefile
all: main

main: main.o eightQueensPuzzle.o
	gcc -o main main.o eightQueensPuzzle.o

main.o: main.c
	gcc -c main.c -g -ansi -pedantic -Wall

Lab4.o: eightQueensPuzzle.c
	gcc -c eightQueensPuzzle.c

clean:
	rm -f *.o main
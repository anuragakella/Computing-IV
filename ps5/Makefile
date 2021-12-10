# Makefile for ps5
CC= g++
CFLAGS= -g -Wall -Werror -std=c++0x -pedantic

all:	EDistance

EDistance:	main.o EDistance.o
	$(CC) main.o EDistance.o -o EDistance -lsfml-system

main.o:	main.cpp EDistance.h
	$(CC) -c main.cpp EDistance.h $(CFLAGS)

EDistance.o:	EDistance.cpp EDistance.h
	$(CC) -c EDistance.cpp EDistance.h $(CFLAGS)

clean:
	rm *.o
	rm *.gch
	rm EDistance

# Copyright 2021 Anurag Akella
# Makefile for ps6
CC = g++
CFLAGS = -g -Wall -Werror -std=c++0x -pedantic
SFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
Boost = -lboost_unit_test_framework

all:	TextWriter test

TextWriter:	TextWriter.o RandWriter.o
	$(CC) TextWriter.o RandWriter.o -o TextWriter

test:	test.o RandWriter.o
	$(CC) test.o RandWriter.o -o test $(Boost)

TextWriter.o:TextWriter.cpp RandWriter.h
	$(CC) -c TextWriter.cpp RandWriter.h $(CFLAGS)

RandWriter.o:RandWriter.cpp RandWriter.h
	$(CC) -c RandWriter.cpp  RandWriter.h $(CFLAGS)

test.o:test.cpp
	$(CC) -c test.cpp $(Boost)

clean:
	rm *.o
	rm *.gch
	rm TextWriter
	rm test
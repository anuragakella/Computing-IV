# Makefile for ps4a
compiler= g++
flags= -g -Wall -Werror -pedantic

all:	ps4a

ps4a:	test.o CircularBuffer.o
	$(compiler) test.o CircularBuffer.o -o ps4a -lboost_unit_test_framework

CircularBuffer.o: CircularBuffer.cpp CircularBuffer.h
	$(compiler) -c CircularBuffer.cpp CircularBuffer.h $(flags)

test.o: test.cpp CircularBuffer.h
	$(compiler) -c test.cpp CircularBuffer.h $(flags)

clean:
	rm *.o
	rm *.gch
	rm ps4a
	rm *.out
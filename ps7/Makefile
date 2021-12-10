#Makefile for ps7
CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
LIBS = -lboost_regex -lboost_date_time

all: main.o
	g++ main.o -o ps7 $(LIBS)

%.o: %.cpp main.cpp
	g++ $(CFLAGS) -o $@ $<

clean:   
	rm ps7 main.o

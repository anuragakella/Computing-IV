# Makefile for ps4a
compiler= g++
flags= -g -std=c++11
SFMLFlags= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:	KSGuitarSim

KSGuitarSim: CircularBuffer.o StringSound.o KSGuitarSim.o 
	$(compiler) KSGuitarSim.o CircularBuffer.o StringSound.o -o KSGuitarSim $(SFMLFlags)

KSGuitarSim.o: KSGuitarSim.cpp
	$(compiler) -c KSGuitarSim.cpp $(flags)

StringSound.o: StringSound.h StringSound.cpp
	$(compiler) -c StringSound.h StringSound.cpp $(flags)

CircularBuffer.o: CircularBuffer.cpp CircularBuffer.h
	$(compiler) -c CircularBuffer.cpp CircularBuffer.h $(flags)

test.o: test.cpp CircularBuffer.h
	$(compiler) -c test.cpp CircularBuffer.h $(flags)

clean:
	rm *.o
	rm *.gch
	rm KSGuitarSim
	rm *.out
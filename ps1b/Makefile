# makefile for PS1B
CC= g++
CFLAGS= -Wall -Werror -ansi -pedantic
SFMLFLAGS= -lsfml-graphics -lsfml-window -lsfml-system

# all command
all:	PhotoMagic

# photomagic
PhotoMagic:	PhotoMagic.o FibLFSR.o
	$(CC) PhotoMagic.o FibLFSR.o -o PhotoMagic $(SFMLFLAGS)

# object files
PhotoMagic.o:	PhotoMagic.cpp FibLFSR.h
	$(CC) -c PhotoMagic.cpp FibLFSR.h $(CFLAGS)

LFSR.o:		FibLFSR.cpp FibLFSR.h
	$(CC) -c FibLFSR.cpp $(CFLAGS)

# clean
clean:
	rm *.o
	rm PhotoMagic
	rm *.h.gch

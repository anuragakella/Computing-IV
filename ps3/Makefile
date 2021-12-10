# Makefile for ps3
# Flags
compiler= g++
cppFlags= -Wall -Werror -pedantic
SFMLFlags= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


all: TFractal

# body executable
TFractal:	TFractal.o Triangle.o
	$(compiler) TFractal.o Triangle.o -o TFractal $(SFMLFlags)

# object files
TFractal.o:	TFractal.cpp Triangle.h Triangle.h
	$(compiler) -c TFractal.cpp Triangle.h $(cppFlags)

# Cleanup
clean:
	rm *.o
	rm TFractal
	rm *.gch
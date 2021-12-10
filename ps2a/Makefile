# Makefile for ps2a
# Flags to save on typing all this out
compiler= g++
cppFlags= -Wall -Werror -pedantic
SFMLFlags= -lsfml-graphics -lsfml-window -lsfml-system


all: NBody

# body executable
NBody:	main.o CelestialBody.o Universe.o
	$(compiler) main.o Universe.o CelestialBody.o -o NBody $(SFMLFlags)

# object files
main.o:	main.cpp CelestialBody.h Universe.h
	$(compiler) -c main.cpp CelestialBody.h Universe.h $(cppFlags)

CelestialBody.o: CelestialBody.cpp CelestialBody.h
	$(compiler) -c CelestialBody.cpp CelestialBody.h $(cppFlags)

Universe.o: Universe.cpp Universe.h
	$(compiler) -c Universe.cpp Universe.h $(cppFlags)

# Cleanup
clean:
	rm *.o
	rm NBody
	rm *.gch

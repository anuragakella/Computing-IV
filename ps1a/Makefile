all: ps1a

FibLSFR.o: FibLSFR.cpp FibLSFR.h
	gcc -c FibLSFR.cpp

test.o: FibLFSR.h FibLFSR.cpp test.cpp
	g++ -c FibLFSR.cpp test.cpp -l boost_unit_test_framework

ps1a: FibLFSR.o test.o
	g++ FibLFSR.o test.o -o ps1a -l boost_unit_test_framework

clean:
	rm test.o FibLFSR.o ps1a
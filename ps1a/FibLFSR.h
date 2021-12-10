/*
*  Computing IV - Assignment - PS1a
*  Instructor: Prof. Yelena Rykalova
*
*  Due Date: 20th September 2021
*
*  Author: Anurag Akella (ID 01990503)
*
*  Description: This program is an implementation of a Fibonacci Linear Feedback Shift Register
                Takes in a seed and generates bits with seed() and numbers with generate(int)
                This is a header file with the FibLFSR class definition
*/
#include <iostream>

class FibLFSR {
    public:
        FibLFSR(std::string seed);
        int step();
        int generate(int k);
        friend std::ostream& operator<< (std::ostream& out, const FibLFSR& fibLFSR);
    private:
        std::string reg;
        int getBit(char a);
        int xorOP(int a, int b);

};
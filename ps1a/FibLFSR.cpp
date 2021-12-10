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
*/


#include "FibLFSR.h"
#include <string>
#include <math.h>

std::ostream& operator<< (std::ostream& out, const FibLFSR& fibLFSR) {
    out << fibLFSR.reg;
    return out;
}

int FibLFSR::getBit(char a) {
    if (a == '1') return 1;
    else if (a == '0') return 0;
    else return -1;
}

FibLFSR::FibLFSR(std::string seed){
    reg = seed;
}

int FibLFSR::xorOP(int a, int b){
    return a != b;
}

// TAPS AT 13, 12, 10
int FibLFSR::step() {
    // storage for the new register after shifting
    std::string new_reg = reg.substr(1);

    // taps, XORing
    // NOT EQUAL = 1; EQUAL = 0
    int tapval = xorOP(reg[0], reg[2]);
    tapval = xorOP(tapval, getBit(reg[3]));
    tapval = xorOP(tapval, getBit(reg[5]));

    FibLFSR::reg = new_reg;
    FibLFSR::reg += std::to_string(tapval);
    return tapval;
}

int FibLFSR::generate(int k) {
    int res = 0;
    for(int i = 0; i < k; i++){
        int x = step();
        std::cout << reg << " " << x << std::endl;
        res = (res * 2) + x;
    }
    return res;
}

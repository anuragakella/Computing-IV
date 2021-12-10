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
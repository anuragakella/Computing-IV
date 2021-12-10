#ifndef EDISTANCE_H
#define EDISTANCE_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdexcept>      
#include <vector>
#include <SFML/System.hpp>

class EDistance
{
  public:
    EDistance();
    EDistance(std::string string_one, std::string string_two);
    ~EDistance();
    int penalty(char a, char b);
    int min(int a, int b, int c);
    int OptDistance();
    std::string Alignment();

  private:
    std::string strone, strtwo;

    
    std::vector< std::vector<int> > mtrx;
};

#endif

#include "EDistance.h"

EDistance::EDistance() {}

EDistance::~EDistance() {}

EDistance::EDistance(std::string string_one, std::string string_two){
  strone = string_one;
  strtwo = string_two;
}

int EDistance::penalty(char a, char b){
  // lambda
  return [](char a, char b) {
    return a == b ? 0 : 1;
  }(a, b);
}

int EDistance::min(int a, int b, int c){
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

int EDistance::OptDistance(){  
  int i, j;
  int N = strone.length();
  int M = strtwo.length();
  std::cout << N << " " << M << std::endl;
  std::cout << sizeof(int) << std::endl;
  // initializing
  // meh, not using, have to garbage collect
  // for(i = 0; i <= M; i++)
    // mtrx.push_back(*new std::vector<int>(N+1, 0));

  for(i = 0; i <= M; i++) {
    std::vector<int> tmp(N+1, 0);
    mtrx.push_back(tmp);
  }

  for(i = 0; i <= M; i++)
    mtrx[i][N] = 2 * (M - i);
  
  for(j = 0; j <= N; j++)
    mtrx[M][j] = 2 * (N - j);
  
  for(i = M - 1; i >= 0; i--)
    for(j = N - 1; j >= 0; j--)
      mtrx[i][j] = min(mtrx[i+1][j+1] + penalty(strone[j], strtwo[i]), mtrx[i+1][j] + 2, mtrx[i][j+1] + 2);
  
  std::cout << mtrx.size() << std::endl;
  std::cout << mtrx[0].size() << std::endl;
  std::cout << sizeof(std::vector<int>) * (mtrx.size() + 1) + (sizeof(int) * mtrx.size() * mtrx[0].size())  << std::endl;


  return mtrx[0][0];
}

std::string EDistance::Alignment(){

  std::ostringstream retstr; 
  int M = strtwo.length(), N = strone.length(), i = 0, j = 0, pen, x1, x2, x3;
  std::string fnstr;

  while(i < M || j < N){
    try{
      pen =  penalty(strone[j], strtwo[i]);
      x1 = mtrx.at(i+1).at(j+1) + pen;
    } catch(const std::out_of_range& error){
      x1 = -1;
    }

    try{
      x2 = mtrx.at(i+1).at(j) + 2;
    } catch(const std::out_of_range& error) {
      x2 = -1;
    }

    try{
      x3 = mtrx.at(i).at(j+1) + 2;
    } catch(const std::out_of_range& error) { 
      x3 = -1;
    }

    if(mtrx[i][j] == x1){
      retstr << strone[j] << " " <<  strtwo[i] << " "  << pen << "\n";
      i++;
      j++;
    } 

    else if(mtrx[i][j] == x2){
      retstr << "- " << strtwo[i] << " 2\n";
      i++;
    }
    
    else if(mtrx[i][j] == x3){
      retstr << strone[j] << " -" << " 2\n";
      j++;
    }
  } 
  
  fnstr = retstr.str();
  return fnstr;
}

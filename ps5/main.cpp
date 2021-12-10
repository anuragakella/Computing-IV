#include "EDistance.h"

int main(int argc, const char* argv[]){
  sf::Clock clock;
  sf::Time t;

  std::string string1, string2;
  std::cin >> string1 >> string2;
  EDistance ed_test(string1, string2);
  
  int distance = ed_test.OptDistance();
  std::string alignment = ed_test.Alignment();

  std::cout << "Edit distance = " << distance << "\n";
  std::cout << alignment; 
  
  //execution time
  t = clock.getElapsedTime();
  std::cout << "Execution time is " << t.asSeconds() << " seconds \n";

  return 0;
}

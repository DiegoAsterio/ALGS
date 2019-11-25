#include <list>
#include <iostream>
#include "tsp.hpp"

int main(){
  std::vector<Point> v = {Point(-21,0), Point(-5,0), Point(-1,0), Point(0,0), Point(1,0), Point(3,0), Point(11,0)};

  std::list<Point> l = closestPair(v);

  for (auto e : l){
    std::cout << e.getX() << std::endl;
  }
  
  return 0;
}

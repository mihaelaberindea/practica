#include "Vector.hpp"
#include "List.hpp"
#include "ListNode.hpp"
#include <cstdlib>

int main(){
      Vector<int> vec;
 
  vec.pushBack(0);
  vec.pushBack(1);
  vec.pushBack(2);
  vec.pushBack(3);
  vec.pushBack(4);
  vec.pushFront(5);

  Vector<int> vec2 = vec; //copy constructor
  vec.print();
  std::cout<< vec.getFront() << " " << vec.getBack() << " " << vec.getElement(1) <<" " << std::endl;

  std::cout << vec.getCapacity() << std::endl;
  vec.reserve(15);
  std::cout << vec.getCapacity() << std::endl;
}
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

  std::cout << vec[0] << std::endl; 
  std::cout << vec[1] << std::endl; 
  std::cout << vec[2] << std::endl; 

  Queue<int, List> myq;
  myq.push(6);
  myq.push(7);
  myq.push(8);
  myq.pop();
  std::cout << myq;

}
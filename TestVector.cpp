#include "Vector.hpp"
#include<cassert>

void TestGetSize()
{
    Vector vec;
    assert(vec.GetSize() == 0);
}
void TestGetCapacity()
{
    Vector vec;
    assert(vec.GetCapacity() == 0);
}
void TestInsert()
{
    Vector vec=
    assert(vec.insert(2));
}
 int main()
 {
     TestGetSize();
     TestGetCapacity();
     TestInsert();

     return 0;
 }
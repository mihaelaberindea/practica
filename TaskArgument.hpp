#ifndef TASKARGUMENT_HPP
#define TASKARGUMENT_HPP
#include <cstddef>
class TaskArgument
{
  public:
    int a;
    int b;
    TaskArgument(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
};
#endif
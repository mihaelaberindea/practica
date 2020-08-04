#include "Algorithms.hpp"
#include "List.hpp"
#include "ListNode.hpp"
#include "PriorityQueue.hpp"
#include "Queue.hpp"
#include "SynchronizedPriorityQueue.hpp"
#include "Task.hpp"
#include "TaskScheduler.hpp"
#include "Vector.hpp"
#include <iostream>

int main()
{
    TaskScheduler scheduler(5);

    TaskArgument arg(1, 2);
    auto future = scheduler.schedule(arg, 0);

    std::cout << future.get().sum << std::endl;
    /* Vector<int> vec;
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

    List<int> list;
    list.pushBack(10);
    list.pushBack(11);
    list.pushFront(13);
    std::cout <<list;
    

    std::vector<int> src = {1, 2, 3, 4, 5};
    std::vector<int> dst = {0, 0, 0, 0, 0};

    copy(src.begin(), dst.begin());

    std::vector<int> vec;
    sort(vec.begin(), vec.end(), [](int lhs, int rhs) { return lhs < rhs; })

        transform(vec.begin(), vec.end(), [](int value) { return value * 2; })

            Vector<int>
                vec1;
    vec1.resize(10);

    pdv::transform(vec.begin(), vec.end(), vec1.begin(), [](int a) { return ++a; });
    std::cout << vec1 << "\n";

    int sum = pdv::reduce(vec.begin(), vec.end(), 0, [](int a, int b) { return a + b; });
    std::cout << sum << "\n";

    int prod = pdv::reduce(vec.begin(), vec.end(), 0, [](int a, int b) { return a * b; });
    std::cout << prod << "\n";
    
    vec.popBack();
    vec.popBack();
    vec.popFront();
    std::cout << "\n";

    std::cout << "erase:\n";
    list.erase(list.begin());
    list.erase(list.end());
    list.erase(list.begin() + 1);
    std::cout << list;
    */

}
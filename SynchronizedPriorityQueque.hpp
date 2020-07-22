#ifndef SYNCHRONIZEDPRIORITYQUEQUE_HPP
#define SYNCHRONIZEDPRIORITYQUEQUE_HPP
#include "Vector.hpp"
#include <cstddef>
#include<thread>
#include<mutex>
template<typename T,typename TContainer, typename TLock=std::mutex>
class SyncronizedPriorityQueque
{
  public:
    SynchronizedPriorityQueque();
    SynchronizedPriorityQueque(const PriorityQueque& rhs);
    ~SynchronizedPriorityQueque();
    SynchronizedPriorityQueque<T,TContainer,TLock>& operator=(const SynchronizedPriorityQueue& rhs);
    size_t getSize();
    void pushElement(T element);
    T pop();
    bool tryPop(T& value);
    void clear();
    bool isEmpty();
    friend std::ostream& operator<<(std::ostream& os, const SynchronizedPriorityQueue<U,UTContainer,UTLock>& sprioq);
    typename TContainer<T>::TIterator begin();
    typename TContainer<T>::TIterator end();

    private:
    TContainer m_container;
    TLock m_lock;
};
#endif
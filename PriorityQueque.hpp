#ifndef PriorityQueque_HPP
#define PriorityQueque_HPP
#include <cstddef>
template <typename T, typename TContainer>
class PriorityQueque
{
    public:
    PriorityQueque();
    PriorityQueque(const PriorityQueque& rhs);
    ~PriorityQueque();
    PriorityQueque<T,TContainer>& operator=(const PriorityQueue& rhs);
    size_t getSize();
    void push(T element);
    T pop(T element);
    void clear();
    bool isEmpty();
    friend std::ostream& operator<<(std::ostream& os, const PriorityQueue<U,UTContainer>& prioq);
    typename TContainer::TIterator begin();
    typename TContainer::TIterator end();
    private:
    TContainer m_container;
};
#include "PriorityQueque.hpp"
#endif
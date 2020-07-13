#include "PriorityQueque.hpp" 
#include <iostream>
#include <string.h>
#include <ostream>
template <typename T, template <typename> typename TContainer>
PriorityQueque<T,TContainer>::Task()
{
    m_container=0;
}
template <typename T, template <typename> typename TContainer>
 PriorityQueque<T,TContainer>::PriorityQueque(const PriorityQueue& rhs);
 {
     m_container=rhs.m_container;
 }
template <typename T, template <typename> typename TContainer>
PriorityQueue<T,TContainer>::~PriorityQueue()
{
    delelte [] this->m_container;
}
template <typename T, template <typename> typename TContainer>
PriorityQueue<T,TContainer>& PriorityQueue<T,TContainer>::operator=(const PriorityQueue& rhs)
{
    m_container = rhs.m_container;
}
template <typename U, template <typename> typename UTContainer>
std::ostream& operator<<(std::ostream& os, const PriorityQueue<U,UTContainer>& q)
{
    os << q.m_container;
    return os;
}
template <typename T, template <typename> typename TContainer>
size_t PriorityQueue<T,TContainer>::getSize()
{
    return m_container.getSize;
}
template <typename T, template <typename> typename TContainer>
void  PriorityQueue<T,TContainer>::push(T element)
{
    m_container.pushBack(element);
}
template <typename T, template <typename> typename TContainer>
T PriorityQueue<T,TContainer>::pop(T element)
{
    T value = m_container.getFront();
    m_container.popFront();
    return value;
}
template <typename T, template <typename> typename TContainer>
void PriorityQueue<T,TContainer>::clear()
{
    m_container.clear();
}

template <typename T, template <typename> typename TContainer>
bool PriorityQueue<T,TContainer>::empty()
{
    return m_container.empty();
}




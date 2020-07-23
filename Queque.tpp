#include "Queque.hpp"
#include <cstdlib>
#include <iostream>
using TIterator = typename TContainer::TIterator;
template <typename T, typename Tcontainer>
Queque<T, Tcontainer>::Queque()
{
}
template <typename T, typename Tcontainer>
Queque<T, Tcontainer>::Queque(const Queque& rhs)
{
    m_container = rhs.m_container;
}
template <typename T, typename Tcontainer>
Queque<T, Tcontainer>::~Queque()
{
}
template <typename T, typename TContainer>
Queue<T, TContainer>& Queue<T, TContainer>::operator=(const Queue& rhs)
{
    m_container = rhs.m_container;
}
template <typename U, template <typename> typename UTContainer>
std::ostream& operator<<(std::ostream& os, const Queue<U, UTContainer>& myq)
{
    os << myq.m_container;
    return os;
}
template <typename T, typename Tcontainer>
size_t getSize()
{
    return m_container.getSize();
}
template <typename T, typename Tcontainer>
void Queque<T, Tcontainer>::push(T element)
{
    m_container.pushBack(element);
}
template <typename T, typename Tcontainer>
void Queque<T, Tcontainer>::pop(T element)
{
    T value = m_container.getFront();
    m_container.popFront();
    return value;
}
template <typename T, typename Tcontainer>
void Queque<T, Tcontainer>::clear()
{
    m_size = 0;
}
template <typename T, typename Tcontainer>
bool Queque<T, Tcontainer>::isEmpty()
{
    return m_container.empty();
}
template <typename T, typename TContainer>
TIterator begin()
{
    return TIterator<T>(m_container)
}
template <typename T, typename TContainer>
TIterator end()
{
    return TIterator<T>(m_container + m_size);
}

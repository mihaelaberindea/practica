#include "Queque.hpp"
#include <iostream>
template <typename T, typename TContainer>
Queque<T, TContainer>::Queque()
{
}
template <typename T, typename TContainer>
Queque<T, TContainer>::Queque(const Queque &rhs)
{
    m_container = rhs.m_container;
}
template <typename T, typename TContainer>
Queque<T, TContainer>::~Queque()
{
}
template <typename T, typename TContainer>
Queque<T, TContainer>& Queque<T, TContainer>::operator=(const Queque &rhs)
{
    m_container = rhs.m_container;
}
template <typename U, typename UTContainer>
std::ostream& operator<<(std::ostream &os, const Queque<U, UTContainer> &myq)
{
    os << myq.m_container;
    return os;
}
template <typename T, typename TContainer>
size_t getSize()
{
    return m_container.getSize();
}
template <typename T, typename TContainer>
void Queque<T, TContainer>::push(T element)
{
    m_container.pushBack(element);
}
template <typename T, typename TContainer>
T  Queque<T, TContainer>::pop(T element)
{
    T value = m_container.getFront();
    m_container.popFront();
    return value;
}
template <typename T, typename TContainer>
void Queque<T, TContainer>::clear()
{
    m_container.clear();
}
template <typename T, typename TContainer>
bool Queque<T, TContainer>::isEmpty()
{
    return m_container.isEmpty();
}
/*template <typename T, typename TContainer>
TIterator begin()
{
    return TIterator<T>(m_container)
}
template <typename T, typename TContainer>
TIterator end()
{
    return TIterator<T>(m_container + m_size);
}
*/

template <typename T, typename TContainer>
typename TContainer::TIterator Queque<T, TContainer>::begin()
{
    return m_container.begin();
}

template <typename T, typename TContainer>
typename TContainer::TIterator Queque<T, TContainer>::end()
{
    return m_container.end();
}


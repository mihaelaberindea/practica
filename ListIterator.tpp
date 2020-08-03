#include "ListIterator.hpp"
#include <iostream>
template <typename T>
ListIterator<T>::ListIterator(ListNode<T>* value)
    : m_value(value)
{
}
template <typename T>
ListIterator<T>::ListIterator(const ListIterator& rhs)
    : m_value(rhs.m_value)
{
}
template <typename T>
ListIterator<T>& ListIterator<T>::operator=(const ListIterator& rhs)
{
    return m_value = rhs.m_value;
    return *this;
}
template <typename T>
bool ListIterator<T>::operator!=(const ListIterator& rhs)
{
    return m_value != rhs.m_value;
    return *this;
}
template <typename T>
bool ListIterator<T>::operator<(const ListIterator& rhs)
{
    if (m_value < rhs.m_value)
        return m_value;
    else
        return rhs.m_value;
}
template <typename T>
ListIterator<T>& ListIterator<T>::operator++()
{
    return ++m_value;
    return *this;
}
template <typename T>
ListIterator<T>& ListIterator<T>::operator--()
{
    return --m_value;
    return *this;
}
template <typename T>
ListIterator<T>& ListIterator<T>::operator+=(std::size_t difference)
{
    return m_value += difference;
    return *this;
}
template <typename T>
ListIterator<T>& ListIterator<T>::operator-=(std::size_t difference)
{
    return m_value -= difference;
    return *this;
}
template <typename T>
ListIterator<T> ListIterator<T>::operator+(std::size_t difference)
{
    ListIterator<T> it;
    it = m_value + difference;
    return it;
}
template <typename T>
ListIterator<T> ListIterator<T>::operator-(std::size_t difference)
{
    ListIterator<T> it;
    it = m_value + difference;
    return it;
}
template <typename T>
T& ListIterator<T>::operator*()
{
    return m_value->getData();
}

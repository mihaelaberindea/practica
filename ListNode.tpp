#include "List.hpp"
#include "ListNode.hpp"
#include <cstdlib>
#include <ostream>
template <typename T>
ListIterator<T>::ListIterator(ListNode* value)
    : m_value(value)
{
}
template <typename T>
ListIterator<T>::ListIterator(const ListIterator& rhs)
{
    m_value = rhs.m_value;
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
ListIterator<T>& ListIterator<T>::operator+(std::size_t difference)
{
    ListIterator<T> it;
    it = m_value + difference;
    return it;
}
template <typename T>
ListIterator<T>& ListIterator<T>::operator-(std::size_t difference)
{
    ListIterator<T> it;
    it = m_value - difference;
    return it;
}
template <typename T>
T& ListIterator<T>::operator*()
{
    return *m_value;
}

template <typename T>
ListNode<T>::ListNode(ListNode* prev, ListNode* next, T data)
{
    m_prev = prev;
    m_next = next;
    m_data = data;
}
template <typename T>
ListNode<T>::ListNode(const ListNode& rhs)
{
    m_prev = rhs.m_prev;
    m_next = rhs.m_next;
    m_data = rhs.m_data;
}
template <typename T>
ListNode<T>::~ListNode()
{
    delete[] m_data;
    m_data = nullptr;
}
template <typename T>
ListNode<T>& ListNode<T>::operator=(const ListNode& rhs)
{
    m_data = rhs.m_data;
    m_next = rhs.m_next;
    m_prev = rhs.m_prev;

    return *this;
}
template <typename T>
T& getPrev()
{
    return m_prev;
}
template <typename T>
ListNode& ListNode<T>::getNext()
{
    return m_next;
}
template <typename T>
void ListNode<T>::setPrev(ListNode* prev)
{
    m_prev = prev;
}
template <typename T>
void ListNode<T>::setNext(ListNode* next)
{
    m_next = next;
}
template <typename T>
T ListNode<T>::getData()
{
    return m_data;
};
template <typename T>
void ListNode<T>::setData(T data)
{
    m_data = data;
}
template <typename U>
std::ostream& operator<<(std::ostream& os, const ListNode<U>& ln)
{
    os << "prev: " << ((ln.m_prev != NULL) ? (ln.m_prev->m_data) : "NULL") << "\n";
    os << "data: " << ln.m_data << "\n";
    os << "next: " << ((ln.m_next != NULL) ? (ln.m_next->m_data) : "NULL") << "\n";
    return os;
}

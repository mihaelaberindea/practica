#include "ListNode.hpp"
#include <cstdlib>
#include <ostream>
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
ListNode<T>* ListNode<T>::getPrev()
{
    return m_prev;
}
template <typename T>
ListNode<T>* ListNode<T>::getNext()
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
T &ListNode<T>::getData()
{
    return m_data;
};
template <typename T>
void ListNode<T>::setData(ListNode* data)
{
    m_data = data->m_data;
    m_prev = data->m_prev;
    m_next = data->m_next;
}
template <typename U>
std::ostream& operator<<(std::ostream& os, const ListNode<U>& ln)
{
    os << "prev: " << ((ln.m_prev != NULL) ? (ln.m_prev->m_data) : "NULL") << "\n";
    os << "data: " << ln.m_data << "\n";
    os << "next: " << ((ln.m_next != NULL) ? (ln.m_next->m_data) : "NULL") << "\n";
    return os;
}

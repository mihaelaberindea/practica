#include "ListNode.hpp"
#include <cstdlib>
template <typename T>
ListNode<T>::ListNode( ListNode*prev, ListNode* next, T data )
{
  m_prev=prev;
  m_next=next;
  m_data=data;
}
template <typename T>
ListNode<T>::ListNode (const ListNode& rhs)
{
  m_prev=rhs.m_prev;
  m_next=rhs.m_next;
  m_data=rhs.m_data
}
template<typename T>
ListNode<T>::~ListNode()
{
  if(m_prev != NULL)
     {
        m_prev->m_next = m_next;
     } 
     if(m_next != NULL)
     {
        m_next->m_prev = m_prev;
     }
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
    return  m_prev;
}
template <typename T>
T& ListNode<T>::getNext()
{
  return m_next;
}
template <typename T>
void ListNode<T>::setPrev(ListNode* prev)
{
    m_prev=prev;
}
template <typename T>
void ListNode<T>::setNext(ListNode* next)
{
  m_next=next;

}
template <typename T>
T& ListNode<T>::getData()
{
  return m_data;
};
template <typename T>
void ListNode<T>::setData(T data)
{
  m_data=data;
}
template<typename U>
std::ostream& operator<<(std::ostream& os, const ListNode<U>& vec)
{
    os << "prev: "
              << ((ln.m_prev != NULL) ?  std::to_string(ln.m_prev->m_data) : "NULL") << "\n";  
    os << "data: " 
              << ln.m_data << "\n"; 
    os << "next: "
              << ((ln.m_next != NULL) ?  std::to_string(ln.m_next->m_data) : "NULL") << "\n";
   return os;
}

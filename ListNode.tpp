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
T& getPrev()
{
    return this-> m_prev;
}
template <typename T>
T& getNext()
{
  return this->m_next;
}
template <typename T>
void ListNode<T>::setPrev(ListNode* prev)
{
    this->m_prev=prev;
}
template <typename T>
void ListNode<T>::setNext(ListNode* next)
{
  this->m_next=next;

}
template <typename T>
T& getData()
{
  return this->m_data;
};
template <typename T>
void ListNode<T>::setData(T data)
{
   this->m_data=data->m_data;
   this->m_next=data->m_next;
   this->m_prev=data->m_prev;
}

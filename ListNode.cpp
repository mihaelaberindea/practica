#include "List.hpp"
#include <cstdlib>
ListNode::ListNode( ListNode*prev, ListNode* next, int data )
{
  m_prev=prev;
  m_next=next;
  m_data=data;
}
ListNode::~ListNode()
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
ListNode*::ListNode::getPrev()
{
    return this-> m_prev;
}
ListNode*::ListNode::getNext()
{
  return this->m_next;
}
void::ListNode::setPrev(ListNode* prev)
{
    this->m_prev=prev;
}
void::ListNode::setNext(ListNode* next)
{
  this->m_next=next;

}
int ListNode:: getData()
{
  return this->m_data;
};
void::ListNode::setData(ListNode* data)
{
   this->m_data=data->m_data;
   this->m_next=data->m_next;
   this->m_prev=data->m_prev;
}

#include "List.hpp"
#include<cstddef>

List::List()
{
    m_size=0;
    m_tail=NULL;
    m_head=NULL;
}
std::size_t List::getSize()
{
    return this->m_size;
}
void List::insert(std::size_t idx , int element)
{
    ListNode* node = new ListNode(NULL,NULL,element);

    ListNode* p = m_head;
    if(idx == 0) 
    {
        pushFront(element);
    }
    if(idx == m_size)
    {
        pushBack(element);
    }
    while(idx)
    {
        p = p->getNext();
        --idx;
    }

    p->getPrev()->setNext(node);
    node->setPrev(p->getPrev());
    p->setPrev(node);
    node->setNext(p);
    
    m_size++;
}
void List::pushFront(int element)
{
    ListNode* node = new ListNode(NULL,NULL,element);

    if(m_head == NULL)
    {
        m_head = m_tail = node;
    }else
    {
        node->setNext(m_head);
        m_head->setPrev(node);
        m_head = node;
    }
    m_size++;
}

void List::pushBack(int element)
{
   ListNode* node = new ListNode(NULL,NULL,element);
   ListNode* p = m_head;
   if(m_head == NULL)
   {
       m_head = m_tail = node;
   }
   if(m_head == m_tail)
   {
       m_head->setNext(node);
       node->setPrev(m_head);
       m_tail = node;
   }
   while(p->getNext() != NULL)
   {
       p = p->getNext();
   }
    p->setNext(node);
    node->setPrev(p);
    m_tail = node;

    m_size++;
}
int::List::getFront()
{
//return this->m_head[0];  ??
}
int::List::getBack()
{
 //return this->m_tail[this->m_size-1];  ??
}
int::List::getElement(std::size_t idx)
{ this->m_size=idx;

}
void::List::clear()
{
     for(size_t i = 0; i < this->m_size; ++i){
        m_head=m_tail=0;
    }

}
bool::List::empty()
{
  bool ok=1;
  while(ok)
  {
    for(size_t i = 0; i < this->m_size; ++i){
            if((m_head && m_tail) == NULL){
                ok = 0;
            }
            
            
        }
        return true;
  }
  return false;
}
List::~List()
{
    ListNode* current = m_head;
    ListNode* next;
    while( current != NULL ) 
    {
        next = current->getNext();
        delete current;
        current = next;
    }
    m_head = NULL;
    m_tail = NULL;
}
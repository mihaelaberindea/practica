#include "List.hpp"
#include<cstddef>
template <typename T>
 ListIterator<T>::ListIterator(T* value):m_value(value)
 {

 }
 template<typename T>
 ListIterator<T>::ListIterator(const ListIterator& rhs)
 {
     m_value=rhs.m_value;
 }
 template<typename T>
  ListIterator<T>& ListIterator<T>::operator=(const ListIterator& rhs)
  {
      return m_value=rhs.m_value;
      return *this;
  }
  template<typename T>
  bool ListIterator<T>::operator!=(const ListIteratorr& rhs)
  {
      return m_value!=rhs.m_value;
  }
  template<typename T>
  bool ListIterator<T>::operator<(const ListIterator& rhs)
  {
       if(m_value<rhs.m_value)
       return m_value;
       else
       return
       rhs.m_value;
  }
  template<typename T>
  ListIterator<T>& ListIterator<T>::operator++()
  {
      return ++m_value;
      return *this;
  }
  template<typename T>
  ListIterator<T>& ListIterator<T>::operator--()
  {
      return --m_value;
      return *this;
  }
  ListIterator<T>& ListIterator<T>::operator+=(std::size_t difference)
      return m_value+=difference;
      return *this;
  }
  ListIterator<T>& ListIterator<T>::operator-=(std::size_t difference)
      return m_value-=difference;
      return *this;
  }
    template<typename T>
  T& ListIterator<T>::operator*()
  {
      return *m_value;
    
  }

template <typename T>
List<T>::List()
{
    m_size=0;
    m_tail=NULL;
    m_head=NULL;
}
template <typename T>
List<T>::List(const ListNode& rhs);
{
    m_size = 0;
    m_head = NULL;
    m_tail = NULL;

   ListNode<T>*p = rhs.m_head;
   while(p != NULL)
   {
       pushBack(p->getData());
       ++m_size;
       p = p->getNext();
   }
}
template <typename T>
size_t List<T>::getSize()
{
    if(m_head == NULL)
     return 0;
    if(m_head == m_tail) 
    return 1;

    size_t size = 0;
    ListNode<T>* p = m_head;
    while(p != NULL)
    {
        p = p->getNext();
        ++size;
    }

    return size;
}
template <typename T>
void List<T>::insert(std::size_t idx , T element)
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
    
    
};

template <typename T>
void List<T>::pushFront(T element)
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
template <typename T>
void List<T>::pushBack(T element)
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
template <typename T>
int List<T>::getFront()
{
  return m_head->getData();
}
template <typename T>
T List<T>::getBack()
{
  return m_tail->getData();
}
template <typename T>
 T List<T>::getElement(std::size_t idx)
{
     this->m_size=idx;

}
template <typename T>
T& List<T>::operator[](std::size_t idx)
{
   ListNode<T>* p = m_head;
   while(idx)
    {
        p = p->getNext();
        --idx;
    }

    return p->getData();
}
template<typename U>
std::ostream& operator<<(std::ostream& os, const List<U>& ln)
{
   ListNode<U>*p = ln.m_head;
   while(p != NULL)
   {
       os<< std::to_string(p->getData()) << " ";
       p = p->getNext();
   }
    os << "\n";
    return os;
}

template <typename T>
void List<T>::clear()
{
    m_size=0;

}
template <typename T>
bool List<T>::isEmpty()
{
  
    if(m_size==0)
    return true;
    else 
    return false;
}
template <typename T>
List<T>::~List()
{
   delete [] m_data;
   m_data=nulptr;
}
 ListIterator<T> List<T>::begin()
 {
     return ListIterator<T>(m_data);
 }
 template<typename T>
 ListIterator<T> List<T>::end()
 {
     return ListIterator<T>(m_data+m_size);
 }
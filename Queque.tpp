#include "Queque.hpp"
#include<iostream>
#include <cstdlib>
 template <typename T, template <typename> typename Tcontainer>
 Queque<T,Tcontainer>::Queque()
 {
     m_container=0;
 }
 template <typename T,template <typename> typename Tcontainer>
 Queque<T,Tcontainer>::Queque(const Queque&rhs)
 {
     m_container=rhs.m_container;
 }
  template <typename T,template <typename> typename Tcontainer>
 Queque<T,Tcontainer>::~Queque()
 {
     delete []this->m_container;
 }
 template <typename T,template <typename> typename Tcontainer>
 size_t getSize()
 {
   return m_container.getSize();

 }
 template <typename T,template <typename> typename Tcontainer>
 void Queque<T,Tcontainer>::push(T element)
 {
    m_container.pushBack(element);
 }
 template <typename T,template <typename> typename Tcontainer>
 void Queque<T,Tcontainer>::pop(T element)
 {
      T value = m_container.getFront();
      m_container.popFront();
      return val;
 }
template <typename T,template <typename> typename Tcontainer>
 void Queque<T,Tcontainer>::clear()
 {
   m_container.clear();
 }
 template <typename T,template <typename> typename Tcontainer>
 bool Queque<T,Tcontainer>::empty()
 {
     m_container.empty();
 }



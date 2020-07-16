#include "PriorityQueque.hpp" 
#include <iostream>
#include <string.h>
#include <ostream>
using TIterator = typename TContainer::TIterator;
template <typename T,typename TContainer>
PriorityQueque<T,TContainer>::PriorityQueque()
{
   
}
template <typename T, typename TContainer>
 PriorityQueque<T,TContainer>::PriorityQueque(const PriorityQueue& rhs);
 {
     m_container=rhs.m_container;
 }
template <typename T,typename TContainer>
PriorityQueue<T,TContainer>::~PriorityQueue()
{
   
}
template <typename T, typename TContainer>
PriorityQueue<T,TContainer>& PriorityQueue<T,TContainer>::operator=(const PriorityQueue& rhs)
{
    m_container = rhs.m_container;
}
template <typename U, template <typename> typename UTContainer>
std::ostream& operator<<(std::ostream& os, const PriorityQueue<U,UTContainer>& q)
{
    os << q.m_container;
    return os;
}
template <typename T, typename TContainer>
size_t PriorityQueue<T,TContainer>::getSize()
{
    return m_container.getSize;
}
template <typename T, typename TContainer>
void  PriorityQueue<T,TContainer>::push(T element)
{
    m_container.pushFront(element);

        std::size_t pos = 0;
        for (std::size_t idx = 0; idx < m_container.size(); ++idx)
        {
            if (m_container[idx] < element)
            {
                pos++;
            }
        }
         m_container.insert(m_container.begin()+pos,element);

}
template <typename T, typename TContainer>
T PriorityQueue<T,TContainer>::pop(T element)
{
    T element= m_container.back();
    m_container.popBack();
    return element;
}
template <typename T,typename TContainer>
void PriorityQueue<T,TContainer>::clear()
{
    m_container=0;
}

template <typename T,typename TContainer>
bool PriorityQueue<T,TContainer>::isEmpty()
{
    return m_container.empty();
}
 template <typename T,typename TContainer>
TIterator begin()
{
   return TIterator<T>(m_container);
}
template <typename T,typename TContainer>
TIterator end()
{
   return TIterator<T>(m_container+m_size);
}






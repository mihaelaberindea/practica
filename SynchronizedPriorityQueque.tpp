#include "SynchronizedPriorityQueque.hpp" 
using TIterator = typename TContainer::TIterator;
template <typename T,typename TContainer,typename TLock>
SyncronizedPriorityQueque<T,TContainer,TLock>::SynchronizedPriorityQueque()
{
   
}
template <typename T, typename TContainer,typename TLock>
 SynchronizedPriorityQueque<T,TContainer,TLock>::SynchronizedPriorityQueque(const SynchronizedPriorityQueque& rhs)
 {   m_lock.lock();
     m_container=rhs.m_container;
     m_lock.unlock();
 }
template<typename T,typename TContainer, typename Tlock>
SynchronizedPriorityQueue<T,TContainer,TLock>::~SynchronizedPriorityQueue()
{
   
}
template <typename T, typename TContainer,typename Tlock >
SynchronizedPriorityQueue<T,TContainer,TLock>& SynchronizedPriorityQueue<T,TContainer,TLock>::operator=(const SynchronizedPriorityQueue& rhs)
{   m_lock.lock();
    m_container = rhs.m_container;
    m_lock.unlock();
}
template <typename U, typename UTContainer>
std::ostream& operator<<(std::ostream& os, const SynchronizedPriorityQueue<U,UTContainer,UTLock>& sprioq)
{  
    os << q.m_container;
    return os;

}
template <typename T, typename TContainer,typename TLock>
size_t SynchronizedPriorityQueue<T,TContainer,Tlock>::getSize()
{   m_lock.lock();
    return m_container.getSize();
    m_lock.unlock();
}
template <typename T, typename TContainer, typename TLock>
void  SynchronizedPriorityQueue<T,TContainer,TLock>::push(T element)
{   
       std::size_t pos = 0;
        m_lock.lock();
        for (std::size_t idx = 0; idx < m_container.size(); ++idx)
        {
            if (m_container[idx] < element)
            {
                pos++;
            }
        }
         m_container.insert(m_container.begin()+pos,element);
        m_lock.unlock();
}
template <typename T, typename TContainer, typename TLock>
T SynchronizedPriorityQueue<T,TContainer,TLock>::pop(T element)
{   m_lock.lock();
    T element= m_container.getBack();
    m_container.popBack();
    m_lock.unlock();
    return element;
    
}
template<typename T, typename TContainer, typename TLock>
bool SynchronizedPriorityQueue<T,TContainer,TLock>::tryPop(T& value)
{
    if(!m_container=isEmpty())
    {
        value=m_container.pop();
        return true;
    }
    return false;
}
template <typename T,typename TContainer, typename TLock>
void SynchronizedPriorityQueue<T,TContainer, TLock>::clear()
{   m_lock.lock();
    m_container=0;
    m_lock.unlock();
}

template <typename T,typename TContainer, typename TLock>
bool SynchronizedPriorityQueue<T,TContainer,TLock>::isEmpty()
{   m_lock.lock();
    return m_container.empty();
    m_lock.unlock();
}
 template <typename T,typename TContainer,typename TLock>
TIterator begin()
{   m_lock.lock();
   return TIterator<T>(m_container);
   m_lock.unlock();
}
template <typename T,typename TContainer,typename TLock>
TIterator end()
{  m_lock.lock();
   return TIterator<T>(m_container+m_size);
   m_lock.unlock();
}






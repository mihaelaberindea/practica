#include "SynchronizedPriorityQueue.hpp"

template <typename T, template <typename> typename TContainer, typename TLock>
SPriorityQueue<T, TContainer, TLock>::SPriorityQueue()
{
    // new TContainer<T>();
}

template <typename T, template <typename> typename TContainer, typename TLock>
SPriorityQueue<T, TContainer, TLock>::SPriorityQueue(const SPriorityQueue& rhs)
{
    std::lock_guard<std::mutex> guard(m_lock);
    m_container = rhs.m_container;
}

template <typename T, template <typename> typename TContainer, typename TLock>
SPriorityQueue<T, TContainer, TLock>::~SPriorityQueue()
{
}

template <typename T, template <typename> typename TContainer, typename TLock>
SPriorityQueue<T, TContainer, TLock>& SPriorityQueue<T, TContainer, TLock>::operator=(const SPriorityQueue& rhs)
{

    std::lock_guard<std::mutex> guard(m_lock);
    m_container = rhs.m_container;
   
}

template <typename U, template <typename> typename UTContainer, typename UTLock>
std::ostream& operator<<(std::ostream& os, const SPriorityQueue<U, UTContainer, UTLock>& q)
{
    os << q.m_container;
    return os;
}

template <typename T, template <typename> typename TContainer, typename TLock>
size_t SPriorityQueue<T, TContainer, TLock>::getSize()
{
    std::lock_guard<std::mutex> guard(m_lock);
    size_t size = m_container.getSize();
    return size;
}

template <typename T, template <typename> typename TContainer, typename TLock>
void SPriorityQueue<T, TContainer, TLock>::push(T& task)
{

    std::lock_guard<std::mutex> guard(m_lock);
    std::size_t pos = 0;
    for (std::size_t idx = 0; idx < m_container.getSize(); ++idx)
    {
        if (m_container[idx] < task)
        {
            pos++;
        }
    }
    m_container.insert(pos, task);
    
}

template <typename T, template <typename> typename TContainer, typename TLock>
void SPriorityQueue<T, TContainer, TLock>::push(T&& task)
{
    std::lock_guard<std::mutex> guard(m_lock);
    std::size_t pos = 0;
    for (std::size_t idx = 0; idx < m_container.getSize(); ++idx)
    {
        if (m_container[idx] < task)
        {
            pos++;
        }
    }
    m_container.insert(m_container.begin() + pos, std::move(task));
    
}

template <typename T, template <typename> typename TContainer, typename TLock>
T SPriorityQueue<T, TContainer, TLock>::pop()
{

    std::lock_guard<std::mutex> guard(m_lock);
    T task = m_container.getBack();
    m_container.popBack();
    return task;
}

template <typename T, template <typename> typename TContainer, typename TLock>
bool SPriorityQueue<T, TContainer, TLock>::tryPop(T& value)
{
    std::lock_guard<std::mutex> guard(m_lock);

    if (!m_container.isEmpty())
    {
        value = std::move(m_container.getBack());
        m_container.popBack();

        m_lock.unlock();
        return true;
    }
    return false;
}

template <typename T, template <typename> typename TContainer, typename TLock>
void SPriorityQueue<T, TContainer, TLock>::clear()
{
    std::lock_guard<std::mutex> guard(m_lock);
    m_container.clear();
    
}

template <typename T, template <typename> typename TContainer, typename TLock>
bool SPriorityQueue<T, TContainer, TLock>::empty()
{
    std::lock_guard<std::mutex> guard(m_lock);
    bool emp = m_container.empty();
    return emp;
}

template <typename T, template <typename> typename TContainer, typename TLock>
typename TContainer<T>::TIterator SPriorityQueue<T, TContainer, TLock>::begin()
{
    std::lock_guard<std::mutex> guard(m_lock);
    typename TContainer<T>::TIterator it = m_container.begin();
    return it;
}

template <typename T, template <typename> typename TContainer, typename TLock>
typename TContainer<T>::TIterator SPriorityQueue<T, TContainer, TLock>::end()
{
    std::lock_guard<std::mutex> guard(m_lock);
    typename TContainer<T>::TIterator it = m_container.end();
    return it;
}
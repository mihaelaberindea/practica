#include "SynchronizedPriorityQueque.hpp"
#include <mutex>
template <typename T, typename TContainer, typename TLock>
SyncronizedPriorityQueque<T, TContainer, TLock>::SynchronizedPriorityQueque()
{
}
template <typename T, typename TContainer, typename TLock>
SynchronizedPriorityQueque<T, TContainer, TLock>::SynchronizedPriorityQueque(const SynchronizedPriorityQueque& rhs)
{
    std::lock_guard<std::mutex> guard(m_lock);
    m_container = rhs.m_container;
}
template <typename T, typename TContainer, typename Tlock>
SynchronizedPriorityQueue<T, TContainer, TLock>::~SynchronizedPriorityQueue()
{
}
template <typename T, typename TContainer, typename Tlock>
SynchronizedPriorityQueue<T, TContainer, TLock>& SynchronizedPriorityQueue<T, TContainer, TLock>::operator=(
    const SynchronizedPriorityQueue& rhs)
{
    std::lock_guard<std::mutex> guard(m_lock);
    m_container = rhs.m_container;
}
template <typename U, typename UTContainer>
std::ostream& operator<<(std::ostream& os, const SynchronizedPriorityQueue<U, UTContainer, UTLock>& sprioq)
{
    os << q.m_container;
    return os;
}
template <typename T, typename TContainer, typename TLock>
size_t SynchronizedPriorityQueue<T, TContainer, Tlock>::getSize()
{
    std::lock_guard<std::mutex> guard(m_lock);
    return m_container.getSize();
}
template <typename T, typename TContainer, typename TLock>
void SynchronizedPriorityQueue<T, TContainer, TLock>::push(T element)
{
    std::size_t pos = 0;
    std::lock_guard<std::mutex> guard(m_lock);
    for (std::size_t idx = 0; idx < m_container.size(); ++idx)
    {
        if (m_container[idx] < element)
        {
            pos++;
        }
    }
    m_container.insert(m_container.begin() + pos, element);
}
template <typename T, typename TContainer, typename TLock>
T SynchronizedPriorityQueue<T, TContainer, TLock>::pop(T element)
{
    std::lock_guard<std::mutex> guard(m_lock);
    T element = m_container.getBack();
    m_container.popBack();
    m_lock.unlock();
    return element;
}
template <typename T, typename TContainer, typename TLock>
bool SynchronizedPriorityQueue<T, TContainer, TLock>::tryPop(T& value)
{
    std::lock_guard<std::mutex> guard(m_lock);
    if (!m_container = isEmpty())
    {
        value = m_container.pop();
        return true;
    }
    return false;
}
template <typename T, typename TContainer, typename TLock>
void SynchronizedPriorityQueue<T, TContainer, TLock>::clear()
{
    std::lock_guard<std::mutex> guard(m_lock);
    m_container.clear();
}

template <typename T, typename TContainer, typename TLock>
bool SynchronizedPriorityQueue<T, TContainer, TLock>::isEmpty()
{
    std::lock_guard<std::mutex> guard(m_lock);
    return m_container.isEmpty();
}
template <typename T, typename TContainer, typename TLock>
TIterator begin()
{
    std::lock_guard<std::mutex> guard(m_lock);
    return TIterator<T>(m_container);
}
template <typename T, typename TContainer, typename TLock>
TIterator end()
{
    std::lock_guard<std::mutex> guard(m_lock);
    return TIterator<T>(m_container + m_size);
}

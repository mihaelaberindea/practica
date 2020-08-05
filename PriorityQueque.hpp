#ifndef PriorityQueque_HPP
#define PriorityQueque_HPP
#include <cstddef>
template <typename T, typename TContainer>
class PriorityQueque
{
  public:
    PriorityQueque();
    PriorityQueque(const PriorityQueque& rhs);
    ~PriorityQueque();
    PriorityQueque<T, TContainer>& operator=(const PriorityQueque& rhs);
    size_t getSize();
    void push(T element);
    T pop(T element);
    void clear();
    bool isEmpty();
    template <typename U, typename UTContainer>
    friend std::ostream& operator<<(std::ostream &os, const PriorityQueque<U, UTContainer> &prioq);
    typename TContainer::TIterator begin();
    typename TContainer::TIterator end();

  private:
    TContainer m_container;
};
#include "PriorityQueque.hpp"
#endif
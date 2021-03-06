#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstddef>

template <typename T, template <typename> typename TContainer>
class Queue
{
  public:
    // using TIterator = typename TContainer::TIterator;
    Queue();
    Queue(const Queue& rhs);
    ~Queue();
   
    Queue<T, TContainer>& operator=(const Queue& rhs);

    size_t getSize();

    void push(T element);
    T pop();

    void clear();
    bool empty();

    template <typename U, template <typename> typename UTContainer>
    friend std::ostream& operator<<(std::ostream& os, const Queue<U, UTContainer>& vec);

    typename TContainer<T>::TIterator begin();
    typename TContainer<T>::TIterator end();

  private:
    TContainer<T> m_container;
    void print();
};

#include "Queue.tpp"
#endif // QUEUE_HPP
#ifndef Queque_HPP
#define Queque_HPP
#include <cstddef>
#include <cstdlib>
#include <ostream>
template <typename T, typename TContainer>
class Queque
{
   public:
     //using TIterator = typename TContainer::TIterator;

     Queque();
     Queque(const Queque& rhs);
     ~Queque();
     Queque<T, TContainer>& operator=(const Queque& rhs);

     template <typename U, typename UTContainer>
     friend std::ostream& operator<<(std::ostream& os, const Queque<U, UTContainer>& myq);
     
     size_t getSize();
     void push(T element);
     T pop(T element);
     void clear();
     bool isEmpty();
     typename TContainer<T>::TIterator begin();
     typename TContainer<T>::TIterator end();
     //TIterator begin();
     //TIterator end();

   private:
     TContainer m_container;
};
#include "Queque.tpp"
#endif

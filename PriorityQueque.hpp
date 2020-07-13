#ifndef PriorityQueque_HPP
#define PriorityQueque_HPP
#include <cstddef>
template <typename T, template <typename> typename TContainer>
class PriorityQueque
{
    public:
    PriorityQueque();
    PriorityQueque(const PriorityQueque& rhs);
    ~PriorityQueque();
    PriorityQueque<T,TContainer>& operator=(const PriorityQueue& rhs);
    size_t getSize();
    void push(T element);
    T pop(T element);
    void clear();
    bool empty();
    friend std::ostream& operator<<(std::ostream& os, const PriorityQueue<U,UTContainer>& prioq);
    
    private:
    TContainer m_container;
};
#include "PriorityQueque.hpp"
#endif
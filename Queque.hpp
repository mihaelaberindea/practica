#ifndef Queque_HPP
#define Queque_HPP
#include <cstddef>
#include <cstdlib>
template<typename T,template <typename> typename Tcontainer>
class Queque
{
    public:
    Queque();
    Queque(const Queque&rhs);
    ~Queque()
    Queue<T,TContainer>& operator=(const Queue& rhs);
    template <typename U, template <typename> typename UTContainer>
    friend std::ostream& operator<<(std::ostream& os, const Queue<U,UTContainer>& myq);
    size_t getSize();
    void push(T element);
    T pop(T element);
    void clear();
    bool empty();
    private:
    Tcontainer m_container;
};
#endif
#include "Queque.tpp"
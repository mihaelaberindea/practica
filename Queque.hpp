#ifndef Queque_HPP
#define Queque_HPP
#include <cstddef>
#include <cstdlib>
template<typename T,typename Tcontainer>
class Queque
{  using TIterator = typename TContainer::TIterator;

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
    bool isEmpty();
    TIterator begin();
    TIterator end();
    private:
    Tcontainer m_container;
};
#endif
//#include "Queque.tpp"
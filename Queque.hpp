#include <cstddef>
#include <cstdlib>
template<typename T,template <typename> typename Tcontainer>
class Queque
{
    public:
    Queque();
    Queque(const Queque&rhs);
    ~Queque()
    std::size_t getSize();
    void push(T element);
    void pop(T element);
    void clear();
    bool empty();
    private:
    Tcontainer m_container;
};
#include "Queque.tpp"
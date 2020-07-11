#include <cstddef>
#include <cstdlib>
template <typename T>
class Vector
{   Vector();
    Vector(const Vector &rhs);
    ~Vector();
    public:
    std::size_t getSize();
    std::size_t getCapacity();
    void insert( std::size_t idx, Tvalue element);
    int pushFront(Tvalue element);
    int pushBack(Tvalue element);
    Tvalue getElement(std::size_t idx);
    void erase (std::size_t idx);
    Tvalue getFront();
    Tvalue getBack();
    int  setElement(std::size_t idx, Tvalue element);
    int setFront(Tvalue element);
    int setBack(Tvalue element);
    void clear();
    bool empty();

    private:
    std::size_t m_capacity;
    std::size_t m_size;
    Tvalue m_data;
    void reserve(std::size_t newCapacity);
    

};;
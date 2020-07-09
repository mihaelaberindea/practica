#include <cstddef>
class Vector
{ 
    Vector();
    ~Vector();
    public:
    std::size_t getSize();
    std::size_t getCapacity();
    void insert( std::size_t idx, int element);
    int pushFront(int element);
    int pushBack(int element);
    int getElement(std::size_t idx);
    int getFront();
    int getBack();
    int  setElement(std::size_t idx, int element);
    int setFront(int element);
    int setBack(int element);
    void clear();
    bool empty();

    private:
    std::size_t m_capacity;
    std::size_t m_size;
    int* m_data;
    void reserve(std::size_t newCapacity);
    

};
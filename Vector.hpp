#include <cstddef>
#include <cstdlib>
template <typename T>
class Vector
{   
    public:
    Vector();
    Vector(const Vector &rhs);
    ~Vector();
    Vector<T>& operator=(const Vector& rhs);
    size_t getSize();
    size_t getCapacity();
    void insert(size_t idx, T element);
    void pushFront(T element);
    void pushBack(T element);
    void erase (size_t idx);
    void popFront();
    void popBack();
    const T& operator[](size_t idx) const;
    T getFront();
    T getBack();
    T& operator[](size_t idx);
    int setFront(T element);
    int setBack(T element);
    void clear();
    bool empty();
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vec);

    private:
    std::size_t m_capacity;
    std::size_t m_size;
    T* m_data;
    
    

};;
#include "Vector.tpp"
#include "Vector.hpp"
#include <cstdlib>
constexpr std::size_t INITIAL_CAPACITY = 15;
 template <typename T>
 VectorIterator<T>::VectorIterator(T* value):m_value(value)
 {

 }
 template<typename T>
 VectorIterator<T>::VectorIterator(const VectorIterator& rhs)
 {
     m_value=rhs.m_value;
 }
 template<typename T>
  VectorIterator<T>& VectorIterator<T>::operator=(const VectorIterator& rhs)
  {
      return m_value=rhs.m_value;
      return *this;
  }
  template<typename T>
  bool VectorIterator<T>::operator!=(const VectorIterator& rhs)
  {
      return m_value!=rhs.m_value;
  }
  template<typename T>
  bool VectorIterator<T>::operator<(const VectorIterator& rhs)
  {
       if(m_value<rhs.m_value)
       return m_value;
       else
       return
       rhs.m_value;
  }
  template<typename T>
  VectorIterator<T>& VectorIterator<T>::operator++()
  {
      return ++m_value;
      return *this;
  }
  template<typename T>
  VectorIterator<T>& VectorIterator<T>::operator--()
  {
      return --m_value;
      return *this;
  }
  template<typename T>
  VectorIterator<T>& VectorIterator<T>::operator+=(std::size_t difference)
      return m_value+=difference;
      return *this;
  }
  template<typename T>
  VectorIterator<T>& VectorIterator<T>::operator-=(std::size_t difference)
      return m_value-=difference;
      return *this;
  }
  template<typename T>
  VectorIterator<T>& VectorIterator<T>::operator+(std::size_t difference)
  {
      VectorIterator<T> it;
      it.m_value = m_value + difference;
      return it;
  }
  template<typename T>
  VectorIterator<T>& VectorIterator<T>::operator-(std::size_t difference)
  {
      VectorIterator<T> it;
      it.m_value = m_value - difference;
      return it;
  }

    template<typename T>
  T& VectorIterator<T>::operator*()
  {
      return *m_value;
    
  }

template< typename T>
 Vector<T>::Vector()
{
   m_capacity=INITIAL_CAPACITY;
   m_size=0;
   m_data=new T[INITIAL_CAPACITY];
};

 template <typename T>
Vector<T>::Vector(const Vector & rhs)
{  delete[] m_data;
  m_size = rhs.m_size;
  m_capacity = rhs.m_capacity; 
  m_data = new T[m_capacity]; 
  std::copy(rhs.m_data, rhs.m_data + rhs.m_size, m_data);
}
 template <typename T>
Vector<T>::Vector(Vector&& rhs)
{
    m_data=rhs.m_data;
    rhs.m_data=nullptr;
}
 template <typename T>
 Vector<T>::~Vector()
 { 
     delete[] m_data;
     m_data=nullptr;
 }

  template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
    if(m_capacity < rhs.m_capacity)
    {
        delete[] m_data;
        m_data = new T[rhs.m_capacity];
    }
    m_capacity = rhs.m_capacity;
    std::copy(rhs.m_data, rhs.m_data + rhs.m_size, m_capacity * sizeof(T));
    
    return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& rhs)
{

    m_capacity = rhs.m_capacity;
    m_size = rhs.m_size;
    m_data = rhs.m_data;

    rhs.m_data = nullptr;
    rhs.m_capacity = rhs.m_size = 0;
    
    return *this;
}

template <typename T>
 size_t Vector<T>:: getSize()
{
    return this->m_size;

}
template< typename T>
size_t Vector<T>:: getCapacity()
{
    return this->m_capacity;

}

template <typename T>
 void Vector<T>:: insert( TIterator ipos, T element){
      if(m_size==m_capacity)
     {
         reserve((1+m_capacity)*2);
     }

      VectorIterator end = end();
      --end;
      for (VectorIterator current = ipos; current != end; ++current)
    {
        VectorIterator  element = current ;
        ++element;     
    }
      
     this->m_size++;
     this->m_data[ipos]=element;
 }
 }

 template<typename T>
 T& Vector<T>::operator[](size_t idx) const
 {
     return m_data[idx];
 }

 template <typename T>
 T& Vector<T>:: getFront()
 {
  return this->m_data[0];
 }

 template <typename T>
  T& Vector<T>:: getBack()
 {
   return this->m_data[this->m_size-1];
 }

  template <typename T>
 T& Vector<T>::operator[]( size_t idx)
 {
     this->m_data[idx];
 }

 template<typename U>
std::ostream& operator<<(std::ostream& os, const Vector<U>& vec)
{
   for(std::size_t idx = 0; idx < vec.m_size; ++idx)
   {
       os << vec.m_data[idx] << " ";
   }
   os << std::endl;

   return os;
}

  template <typename T>
 int Vector<T>::pushFront(T element)
 {
     insert(0,element);
 }

  template <typename T>
 int Vector<T>::pushBack(T element)
 {
     if(m_size == m_capacity)
     {
         reserve((1+m_capacity)*2);
     }
     m_data[m_size]=element;
     m_size++;
 }
 
  template <typename T>
 void Vector<T>:: reserve(std::size_t newCapacity)
 {
     if(this->m_capacity<newCapacity)
     {
         T* newData= new int [newCapacity];
         this->m_capacity=newCapacity;
         for(size_t i=0;i<this->m_size;++i)
         {
             newData[i]=this->m_data[i];
         }
         delete [] this->m_data;
         this->m_data=newData;
     }
 }
 void Vector<T>:: resize( size_t newSize)
 {
     if(this->m_size<newSize)
     {
        for(std::size_t idx = m_size; idx < newSize; ++idx)
        {
            m_data[idx] = T();
        }

     }else
       {
        reserve((m_capacity + 1) * 2);
       }
      m_size = newSize;
 }

  template <typename T>
 void Vector<T>::clear()
 {
   m_size=0;
 }
  
  template <typename T>
 bool Vector<T>::isEmpty()
{
   return m_size=0;
}
 
 template <typename T>
 void Vector<T>::erase(VectorIterator pos)
 {
     VectorIterator end = end();
      --end;

    for (VectorIterator current = pos; current != end; ++current)
    {
        VectorIterator next = current;
        ++next;

        current = next;        
    }
 }
 template<typename T>
 VectorIterator<T> Vector<T>::begin()
 {
     return VectorIterator<T>(m_data);
 }
 template<typename T>
 VectorIterator<T> Vector<T>::end()
 {
     return VectorIterator<T>(m_data+m_size);
 }
 #include "Vector.hpp"
#include <cstdlib>
 template <typename T>
Vector<T>::Vector(const Vector &rhs)
{
  m_size = rhs.m_size;
  m_capacity = rhs.m_capacity; 
 m_data = new T[m_capacity]; 
 memcpy(m_data, rhs.m_data, m_capacity * sizeof(T));
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
template< typename T>
 Vector<T>::Vector()
{
   m_capacity=0;
   m_size=0;
   m_data=0;
};
template <typename T>
 void Vector<T>:: insert( size_t idx, T element){
     if(idx >= 0 && idx <= this->m_size){
        for(size_t i = idx; i < this->m_size - 1; ++i){
            this->m_data[i+1] = this->m_data[i];
            this->m_size++;
        }
     this->m_data[idx]=element;
 }
 }
 template<typename T>
 T Vector<T>::getElement(size_t idx)
 {
     return m_data[idx];
 }
  template <typename T>
 int Vector<T>::setElement( size_t idx, T element)
 {
     this->m_data[idx]=element;
 }
 template <typename T>
 T Vector<T>:: getFront()
 {
  return this->m_data[0];
 }
 template <typename T>
  T getBack()
 {
   return this->m_data[this->m_size-1];
 }
  template <typename T>
 int Vector<T>::pushFront(T element)
 {
   if(this->m_capacity>this->m_size)
   {
       for(size_t i=m_size;i>0;++i)
       {
           this->m_data[i]=this->m_data[i+1];
       }
       this->m_data[0]= element;
   }
 }
  template <typename T>
 int Vector<T>::pushBack(T element)
 {
     if(this->m_capacity>this->m_size)
     {
         for(size_t i=m_size;i>0;--i)
         {
             this->m_data[i]=this->m_data[i-1];
         }
         this->m_data[0]=0;
     }
 }
 
  template <typename T>
 Vector<T>::~Vector()
 { delete []this->m_data;
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
 template <typename T>
 void Vector<T>::clear()
 {
   
    for(size_t i = 0; i < this->m_size; ++i){
        this->m_data[i] = 0;
    }
 }
  template <typename T>
 bool Vector<T>::empty()
{
    bool ok = 1;
    while(ok)
    {
        for(size_t i = 0; i < this->m_size; ++i){
            if(m_data[i] == NULL){
                ok = 0;
            }
        }
        return true;
    }
    return false;
   

}
 template <typename T>
 void Vector<T>::erase(size_t idx)
 {
  delete[] this->m_data[idx];
 }
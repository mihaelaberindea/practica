#include "Vector.hpp"
#include <cstdlib>
std::size_t Vector::getSize()
{
    return this->m_size;

}
std::size_t Vector::getCapacity()
{
    return this->m_capacity;

}

Vector:: Vector()
{
    for(std::size_t idx=0;idx<Vector::getCapacity(); +idx)
    {
        this->m_data[idx]= std::rand();
    }
};
 void Vector:: insert( std::size_t idx, int element){
     if(idx >= 0 && idx <= this->m_size){
        for(size_t i = idx; i < this->m_size - 1; ++i){
            this->m_data[i+1] = this->m_data[i];
            this->m_size++;
        }
     this->m_data[idx]=element;
 }
 }
 int Vector:: getElement(std::size_t idx)
 {
     this->m_data[idx]=0;
 }

 int Vector::setElement(std::size_t idx, int element)
 {
     this->m_data[idx]=element;
 }
 int Vector::getFront()
 {
  return this->m_data[0];
 }
 int Vector::getBack()
 {
   return this->m_data[this->m_size-1];
 }
 int Vector::pushFront(int element)
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
 int Vector:: pushBack(int element)
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
 Vector::~Vector()
 { for(std:: size_t idx=0 ;idx <Vector::getCapacity(); +idx)
    this->m_data[idx]=0;
 }
 void Vector::reserve(std::size_t newCapacity)
 {
     if(this->m_capacity<newCapacity)
     {
         int* newData= new int [newCapacity];
         this->m_capacity=newCapacity;
         for(size_t i=0;i<this->m_size;++i)
         {
             newData[i]=this->m_data[i];
         }
         delete [] this->m_data;
         this->m_data=newData;
     }
 }

 void Vector::clear()
 {
   
    for(size_t i = 0; i < this->m_size; ++i){
        this->m_data[i] = 0;
    }
 }
 bool Vector::empty()
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
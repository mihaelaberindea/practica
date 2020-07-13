#pragma once
#include <cstddef>
#include "ListNode.hpp"
template<typename T>
 class List 
 {
     public:
      List();
      List(const ListNode& rhs);
      ~List();
    std:: size_t getSize();
    void insert(std::size_t idx , T element);
    void pushFront(T element);
    void pushBack(T element);
    T getElement(std::size_t idx);
    int getFront();
    T getBack();
    void erase(std::size_t idx)
    void popFront();
    void popBack();
    void setElement(std::size_t idx, T element);
    void setFront(T element);
    void setBack(T element);
    void clear();
    bool empty();

    private:
    size_t m_size;
    ListNode* m_head;
    ListNode* m_tail;


 };
 #include "List.tpp"
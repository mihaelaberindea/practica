#pragma once
#ifndef LIST_HPP
#define LIST_HPP
#include "ListIterator.hpp"
#include "ListNode.hpp"
#include <cstddef>
template <typename T>
class List
{
  public:
    List();
    List(const List& rhs);
    List(List&& rhs);
    ~List();
    List<T>& operator=(const List& rhs);
    const T& operator[](std::size_t idx) const; // erase
    T& operator[](std::size_t idx);             // setElement
    size_t getSize();
    void insert(std::size_t idx, T element);
    void pushFront(T element);
    void pushBack(T element);
    T getElement(std::size_t idx);
    int getFront();
    T getBack();
    void popFront();
    void popBack();
    void setFront(T element);
    void setBack(T element);
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const List<U>& vec);
    void clear();
    bool isEmpty();
    ListIterator<T> begin();
    ListIterator<T> end();

  private:
    std::size_t m_size;
    ListNode<T>* m_head;
    ListNode<T>* m_tail;
};
#endif
#include "List.tpp"
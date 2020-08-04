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
    using TIterator = ListIterator<T>;

    List();
    List(const List &rhs);
    List(List &&rhs);
    ~List();
    List<T> &operator=(const List<T> &rhs);
    const T &operator[](std::size_t idx) const; // erase
    T &operator[](std::size_t idx);             // setElement
    size_t getSize();
    void insert(TIterator pos, const T& element);
    void insert(TIterator pos, T&& element);
    void pushFront(const T& element);
    void pushFront(T&& element);
    T &getFront();
    T &getBack();
    void pushBack(const T& element);
    void pushBack(T&& element);
    void erase(TIterator pos);
    void popFront();
    void popBack();
    void setFront(T element);
    void setBack(T element);
    template <typename U>
    friend std::ostream& operator<<(std::ostream &os, const List<U> &vec);
    void clear();
    bool isEmpty();
    TIterator begin();
    TIterator end();

  private:
    std::size_t m_size;
    ListNode<T>* m_head;
    ListNode<T>* m_tail;
};
#endif
#include "List.tpp"
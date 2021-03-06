#ifndef LIST_HPP
#define LIST_HPP

#include "ListIterator.hpp"
#include "ListNode.hpp"
#include <cstddef>
#include <iostream>

template <typename T>
class List
{
  public:
    using TIterator = ListIterator<T>;

    List();
    List(const List& rhs);
    List(List&& rhs);
    ~List();

    List<T>& operator=(const List<T>& rhs);
    List<T>& operator=(List<T>&& rhs);

    std::size_t getSize();

    void insert(TIterator pos, const T& element);
    void insert(TIterator pos, T&& element);

    void pushFront(const T& element);
    void pushFront(T&& element);

    void pushBack(const T& element);
    void pushBack(T&& element);

    void erase(TIterator pos);
    void popFront();
    void popBack();

    const T& operator[](std::size_t idx) const;
    T& getFront();
    T& getBack();

    T& operator[](std::size_t idx);
    void setElement(std::size_t idx, T element);
    void setFront(T element);

    void clear();
    bool isEmpty();

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const List<U>& vec);

    auto begin();
    auto end();

  private:
    std::size_t m_size;
    ListNode<T>* m_head;
    ListNode<T>* m_tail;

    void print();
    T getElement(std::size_t idx);
    void setBack(T element);
};

#include "List.tpp"
#endif // LIST_HPP
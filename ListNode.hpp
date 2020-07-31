#ifndef LISTNODE_HPP
#define LISTNODE_HPP

#include <cstddef>
template <typename T>
class ListIterator
{
  public:
    ListIterator(ListNode* value);
    ListIterator(const ListIterator& rhs);
    ListIterator<T>& operator=(const ListIterator& rhs);
    bool operator!=(const ListIterator& rhs);
    bool operator<(const ListIterator& rhs);
    ListIterator<T>& operator++();
    ListIterator<T>& operator--();
    ListIterator<T>& operator+=(std::size_t difference);
    ListIterator<T>& operator-=(std::size_t difference);
    ListIterator<T>& operator+(std::size_t difference);
    ListIterator<T>& operator-(std::size_t difference);
    T& operator*();

  private:
    ListNode* m_value;
};
template <typename T>
class ListNode
{
  public:
    ListNode(ListNode* prev, ListNode* next, T data);
    ListNode(const ListNode& rhs) ~ListNode();
    ~ListNode();
    ListNode<T>& operator=(const ListNode& rhs);
    ListNode* getPrev();
    ListNode* getNext();
    void setPrev(ListNode* prev);
    void setNext(ListNode* next);
    T getData();
    void setData(T data);
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const ListNode<U>& task);

  private:
    ListNode* m_prev;
    ListNode* m_next;
    T m_data;
};
#endif
#include "ListNode.tpp"
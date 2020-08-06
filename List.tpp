#include "List.hpp"
#include <iostream>

template <typename T>
List<T>::List()
{
    m_size = 0;
    m_head = NULL;
    m_tail = NULL;

    std::cout << "List Ctor" << std::endl;
}

template <typename T>
List<T>::List(const List& rhs)
{
    m_size = 0;
    m_head = NULL;
    m_tail = NULL;

    ListNode<T>* p = rhs.m_head;
    while (p != NULL)
    {
        pushBack(p->getData());
        ++m_size;
        p = p->getNext();
    }

    std::cout << "List Copy Ctor" << std::endl;
}

template <typename T>
List<T>::List(List&& rhs)
{
    m_size = rhs.m_size;
    rhs.m_size = 0;

    m_head = rhs.m_head;
    rhs.m_head = nullptr;

    m_tail = rhs.m_tail;
    rhs.m_tail = nullptr;

    std::cout << "List Move Ctor" << std::endl;
}

template <typename T>
List<T>::~List()
{
    ListNode<T>* current = m_head;
    ListNode<T>* next;
    while (current != NULL)
    {
        next = current->getNext();
        delete current;
        current = next;
    }
    m_head = NULL;
    m_tail = NULL;

    std::cout << "List Dtor" << std::endl;
}

template <typename T>
const T& List<T>::operator[](std::size_t idx) const
{
    ListNode<T>* p = m_head;
    while (idx)
    {
        p = p->getNext();
        --idx;
    }

    return p->getData();
}

template <typename T>
T& List<T>::operator[](std::size_t idx)
{
    ListNode<T>* p = m_head;
    while (idx)
    {
        p = p->getNext();
        --idx;
    }

    return p->getData(); // facut sa returneze referinta
}

template <typename T>
List<T>& List<T>::operator=(const List& rhs)
{
    m_size = 0;
    m_head = NULL;
    m_tail = NULL;

    ListNode<T>* p = rhs.m_head;
    while (p != NULL)
    {
        pushBack(p->getData());
        ++m_size;
        p = p->getNext();
    }
    std::cout << "List Copy Assignment Op" << std::endl;
    return *this;
}

template <typename T>
List<T>& List<T>::operator=(List&& rhs)
{
    m_size = rhs.m_size;
    rhs.m_size = 0;

    m_head = rhs.m_head;
    rhs.m_head = NULL;

    m_tail = rhs.m_tail;
    rhs.m_tail = NULL;

    std::cout << "List Move Assignment Op" << std::endl;
    return *this;
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const List<U>& ln)
{
    ListNode<U>* p = ln.m_head;
    while (p != NULL)
    {
        os << p->getData() << " ";
        p = p->getNext();
    }
    os << "\n";
    return os;
}

template <typename T>
void List<T>::insert(TIterator pos, const T& element)
{
    // if(pos < 0 || pos > m_size) return;

    if (!(pos != begin()))
    {
        pushFront(element);
        return;
    }
    if (!(pos != end()))
    {
        pushBack(element);
        return;
    }

    ListNode<T>* node = new ListNode<T>(NULL, NULL, element);
    ListNode<T>* p = pos.get_m_value();

    p->getPrev()->setNext(node);
    node->setPrev(p->getPrev());
    p->setPrev(node);
    node->setNext(p);

    ++m_size;
}

template <typename T>
void List<T>::insert(TIterator pos, T&& element)
{
    // if(pos < 0 || pos > m_size) return;

    if (!(pos != begin()))
    {
        pushFront(std::move(element));
        return;
    }
    if (!(pos != end()))
    {
        pushBack(std::move(element));
        return;
    }

    ListNode<T>* node = new ListNode<T>(nullptr, nullptr, std::move(element));
    ListNode<T>* p = pos.get_m_value();

    p->getPrev()->setNext(node);
    node->setPrev(p->getPrev());
    p->setPrev(node);
    node->setNext(p);

    ++m_size;
}

template <typename T>
void List<T>::pushFront(const T& element)
{
    ListNode<T>* node = new ListNode<T>(nullptr, nullptr, element);

    if (m_head == NULL)
    {
        m_head = m_tail = node;
    }
    else
    {
        node->setNext(m_head);
        m_head->setPrev(node);
        m_head = node;
    }
    ++m_size;
}

template <typename T>
void List<T>::pushFront(T&& element)
{
    ListNode<T>* node = new ListNode<T>(nullptr, nullptr, std::move(element));

    if (m_head == NULL)
    {
        m_head = m_tail = node;
    }
    else
    {
        node->setNext(m_head);
        m_head->setPrev(node);
        m_head = node;
    }
    ++m_size;
}

template <typename T>
void List<T>::pushBack(const T& element)
{

    ListNode<T>* node = new ListNode<T>(nullptr, nullptr, element);
    if (m_head == NULL)
    {
        m_head = m_tail = node;
        return;
    }

    m_tail->setNext(node);
    node->setPrev(m_tail);
    m_tail = node;

    ++m_size;
}

template <typename T>
void List<T>::pushBack(T&& element)
{
    ++m_size;

    ListNode<T>* node = new ListNode<T>(nullptr, nullptr, std::move(element));
    if (m_head == NULL)
    {
        m_head = m_tail = node;
        return;
    }

    m_tail->setNext(node);
    node->setPrev(m_tail);
    m_tail = node;
}

template <typename T>
T List<T>::getElement(size_t idx)
{
    if (idx < 0 || idx > m_size)
        return 0;
    ListNode<T>* p = m_head;
    if (idx == 0)
    {
        return m_head->getData();
    }
    if (idx == m_size)
    {
        return m_tail->getData();
    }
    while (idx)
    {
        p = p->getNext();
        --idx;
    }
    return p->getData();
}

template <typename T>
T& List<T>::getFront()
{
    return m_head->getData();
}

template <typename T>
T& List<T>::getBack()
{
    return m_tail->getData();
}

template <typename T>
size_t List<T>::getSize()
{
    return m_size;
}

template <typename T>
void List<T>::erase(TIterator pos)
{
    ListNode<T>* p = m_head;
    if (!(pos != begin()))
    {
        popFront();
        return;
    }
    if (!(pos != end()))
    {
        popBack();
        return;
    }
    while (pos != begin())
    {
        p = p->getNext();
        --pos;
    }

    delete p;
    --m_size;
}

template <typename T>
void List<T>::popFront()
{
    ListNode<T>* p = m_head;
    m_head = m_head->getNext();
    delete p;
    --m_size;

    if (m_size == 0)
    {
        m_head = m_tail = nullptr;
    }
}

template <typename T>
void List<T>::popBack()
{
    if (m_head != NULL)
    {
        ListNode<T>* p = m_tail;
        m_tail = m_tail->getPrev();
        delete p;
        --m_size;

        if (m_size == 0)
        {
            m_head = m_tail = nullptr;
        }
    }
}

template <typename T>
void List<T>::setElement(size_t idx, T element)
{
    if (idx < 0 || idx > m_size)
        return;

    ListNode<T>* p = m_head;
    if (idx == 0)
    {
        setFront(element);
        return;
    }
    if (idx == m_size)
    {
        setBack(element);
        return;
    }
    while (idx)
    {
        p = p->getNext();
        --idx;
    }

    p->setDataT(element);
}

template <typename T>
void List<T>::setFront(T element)
{
    m_head->setDataT(element);
}

template <typename T>
void List<T>::setBack(T element)
{
    m_tail->setDataT(element);
}

template <typename T>
void List<T>::clear()
{
    ListNode<T>* p = m_head;
    ListNode<T>* q;
    while (p != NULL)
    {
        q = p->getNext();
        delete p;
        p = q;
    }

    m_head = m_tail = NULL;
    m_size = 0;
}

template <typename T>
bool List<T>::isEmpty()
{
    return m_size == 0;
}

template <typename T>
ListIterator<T> List<T>::begin()
{
    return ListIterator<T>(m_head);
}

template <typename T>
ListIterator<T> List<T>::end()
{
    return ListIterator<T>(m_tail) + 1;
}
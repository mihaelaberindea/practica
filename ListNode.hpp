#include <cstddef>
template <typename T>
class ListNode
{
    public:
    ListNode ( ListNode* prev, ListNode* next,  T data);
    ListNode (const ListNode& rhs)
   ~ListNode();
    ListNode* getPrev();
     ListNode* getNext();
    void setPrev(ListNode* prev);
    void setNext(ListNode* next);
     T getData();
   void setData(T data);
    private:
    ListNode* m_prev;
    ListNode* m_next;
    T m_data;

    
};
#include <cstddef>
class ListNode
{
    public:
    ListNode ( ListNode* prev, ListNode* next, int data);
   ~ListNode();
    ListNode* getPrev();
     ListNode* getNext();
    void setPrev(ListNode* prev);
    void setNext(ListNode* next);
   int getData();
   void setData(ListNode* data);
    private:
    ListNode* m_prev;
    ListNode* m_next;
    int m_data;

    
};
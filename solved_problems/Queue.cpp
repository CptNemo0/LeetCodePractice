#include "minclude.h"

struct LinkedListNode
{
    LinkedListNode* next;
    int val;
};


class Queue
{
public:
    LinkedListNode* front = nullptr;
    LinkedListNode* back = nullptr;

    LinkedListNode* last = nullptr;

    Queue()
    {
        front = new LinkedListNode();
        last = new LinkedListNode();
        front->next = back;
        last->next = back;
    }

    LinkedListNode* top()
    {
        return front->next;
    }

    LinkedListNode* pop()
    {
        auto return_value = front->next;
        if(front->next)
        {
            front->next = front->next->next;
        }

        if(!front->next)
        {
            last->next = back;
        }
        return return_value;
    }

    void push(int val)
    {
        auto new_node = new LinkedListNode();
        new_node->val = val;
        new_node->next = back;
        if(!front->next && !last->next)
        {
            front->next = new_node;
            last->next = new_node;
        }
        else if(last->next && front->next)
        {
            last->next->next = new_node;
            last->next = new_node;
        }
    }  
};

int main()
{
    Queue q {};

    for(int i = 0 ; i < 100 ; i++)
    {
        q.push(i);
    }

    for(int i = 0 ; i < 100 ; i++)
    {
        auto popped = q.pop();
        std::cout<<popped->val<<endl;
    }
}
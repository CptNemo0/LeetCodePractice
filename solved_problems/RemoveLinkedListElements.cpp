#include<iostream>
#include <pplwin.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val)
{
    if(!head)
    {
        return head;
    }

    while(head && head->val == val)
    {
        head = head->next;
    }

    ListNode* current = head;

    while(current)
    {
        if(current->next)
        {
            if(current->next->val == val)
            {
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }
        else
        {
            break;
        }
    }

    return head;
}

int main()
{
    return 0;
}

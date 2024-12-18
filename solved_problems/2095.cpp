#include "minclude.h"

class Solution
{
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        ListNode* previous = head;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            previous = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        previous->next = slow->next;
        return head;
    }
};
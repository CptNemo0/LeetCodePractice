#include <iostream>

using  namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* current = head;

    while (current)
    {
        if (current->next)
        {
            if (current->next->val == current->val)
            {
                if (current->next->next)
                {
                    current->next = current->next->next;
                }
                else
                {
                    current->next = nullptr;
                }
            }
        }

        if (current->val != current->next->val)
        {
            current = current->next;
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
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(1);
    ListNode* c = new ListNode(2);

    a->next = b;
    b->next = c;

    deleteDuplicates(a);

    return 0;
}

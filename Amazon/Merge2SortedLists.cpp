struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(!list1 && !list2) return nullptr;
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* head = nullptr;
        
        if(list1->val < list2->val)
        {
            head = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            list2 = list2->next;
        }

        ListNode* current = head;

        while(list1 || list2)
        {
            if(!list1)
            {
                current->next = list2;
                return head;
            }

            if(!list2)
            {
                current->next = list1;
                return head;
            }

            if(list1->val < list2->val)
            {
                current->next = list1;
                list1 = list1->next;
                current = current->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
                current = current->next;
            }
        }

        return head;
    }
};
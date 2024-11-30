struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(!l1 && !l2)
        {
            return new ListNode(0);
        }

        if(!l1)
        {
            return l2;
        }

        if(!l2)
        {
            return l1;
        }

        ListNode* return_value = new ListNode((l1->val + l2->val) % 10);
        int memory = (l1->val + l2->val) >= 10;

        ListNode* current = return_value;
        l1 = l1->next;
        l2 = l2->next;

        while(l1 || l2)
        {
            int v1 = 0;
            int v2 = 0;
            if(l1)
            {
                v1 = l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                v2 = l2->val;
                l2 = l2->next;
            } 

            int nv = (v1 + v2 + memory);
            memory = nv >= 10;
            nv = nv % 10;

            ListNode* nn = new ListNode(nv);
            current->next = nn;
            current = current->next;
        }

        if(memory)
        {
            ListNode* nn = new ListNode(1);
            current->next = nn;
            current = current->next;
        }

        return return_value;
    }
};


int main()
{
    return 0;
}
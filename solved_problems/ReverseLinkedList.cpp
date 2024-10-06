struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) 
{
    if(head == nullptr)
    {
        return head;
    }

    if(head->next == nullptr)
    {
        return head;
    }

    auto A = head;
    auto B = A->next;
    auto C = B->next;

    A->next = nullptr;
    B->next = A;

    if(C == nullptr)
    {
        return B;
    }    

    A = B;
    B = C;
    C = C->next;

    while(true)
    {
        // A is already pointing back
        B->next = A;

        if(C == nullptr)
        {
            return B;
        }

        A = B;
        B = C;
        C = C->next;
    }
}

int main()
{
    return 0;
}
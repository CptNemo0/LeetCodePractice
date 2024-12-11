struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (slow && fast && fast->next)
    {
        if(fast == slow) return true;
        slow = slow->next;
        fast = fast->next->next;

    }
    return false;
}

int main()
{
    return 0;
}

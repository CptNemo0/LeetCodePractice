struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


void deleteNode(ListNode* node)
{
    ListNode* current = node;

    while (current)
    {
        if(current->next)
        {
            current->val = current->next->val;

            if(!current->next->next)
            {
                current->next = nullptr;
            }
        }
        current = current->next;
    }
}

int main()
{

}

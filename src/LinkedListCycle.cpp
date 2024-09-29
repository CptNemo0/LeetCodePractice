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

    ListNode* current = head;

    while (true)
    {
        if(current == current->next)
        {
            return true;
        }

        if(current->next)
        {
            //because nobody said that the list must remain intact
            ListNode* next = current->next;
            current->next = current;
            current = next;
        }
        else
        {
            break;
        }

    }
    return false;
}

int main()
{
    return 0;
}

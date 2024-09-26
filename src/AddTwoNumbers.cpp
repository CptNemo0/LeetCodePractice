struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* retun_value = new ListNode();
    ListNode* current = retun_value;

    ListNode* current_a = l1;
    ListNode* current_b = l2;

    int memory = 0;

    while(current_a != nullptr || current_b != nullptr || memory != 0)
    {
        int num_a = (current_a != nullptr) ? current_a->val : 0;
        int num_b = (current_b != nullptr) ? current_b->val : 0;

        int sum = num_a + num_b + memory;
        int new_digit = 0;
        
        memory = sum/10;
        new_digit = sum%10;
        
        current_a = (current_a != nullptr) ? current_a->next : nullptr;
        current_b = (current_b != nullptr) ? current_b->next : nullptr;
        current->val = new_digit;

        if(current_a != nullptr || current_b != nullptr || memory != 0)
        {
            ListNode* new_node = new ListNode(0);
            current->next = new_node;
            current = current->next;
        }        
    }

    return retun_value;
}

int main()
{

}
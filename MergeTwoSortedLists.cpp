struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if (!list1 && !list2)
    {
        return nullptr;
    }

    if (!list1 && list2)
    {
        return list2;
    }

    if (list1 && !list2)
    {
        return list1;
    }

    ListNode* return_value = new ListNode();

    if(list1->val >= list2->val)
    {
        return_value->val = list2->val;
        list2 = list2->next;
    }   
    else
    {
        return_value->val = list1->val;
        list1 = list1->next;
    }
    return_value->next = mergeTwoLists(list1, list2);
    return return_value;
}

int main()
{

}
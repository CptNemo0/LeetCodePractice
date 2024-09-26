#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

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

void LogList(ListNode* head)
{
    ListNode* current = head;

    while(current != nullptr)
    {
        cout<<current->val<<" ";
        current = current->next;
    }
    cout<<"\n";
}

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    int n = static_cast<int>(lists.size());

    if(n == 0)
    {
        return nullptr;
    }
    
    while(n > 1)
    {
        vector<ListNode*> merged_lists;

        for(int i = 0 ; i < n ; i += 2)
        {
            auto list1 = lists[i];

            cout<<"list1: ";
            LogList(list1);

            auto list2 = i + 1 < n ? lists[i + 1] : nullptr;

            cout<<"list2: ";
            LogList(list2);

            auto merged = mergeTwoLists(list1, list2);

            cout<<"merged: ";
            LogList(merged);

            merged_lists.push_back(merged);
        }

        lists = merged_lists;
        
        n = static_cast<int>(lists.size());

        for(int i = 0 ; i < n ; i++)
        {
            LogList(lists[i]);
        }
    }

    return lists[0];
}

ListNode* CreateList(initializer_list<int> list)
{
    ListNode* head = new ListNode(*list.begin());

    ListNode* current = head;
    for(int i = 1 ; i < list.size() ; i++)
    {
        ListNode* node = new ListNode(*(list.begin() + i));
        current->next = node;
        current = current->next;
    }

    return head;
}

int main()
{
    vector<ListNode*> lists
    {
        CreateList({1, 4, 5}),
        CreateList({1, 3, 4}),
        CreateList({2, 6}),
    }; 

    LogList(mergeKLists(lists));
} 
//clang++ MergeKSortedLists.cpp -o MergeKSortedLists.exe; ./MergeKSortedLists.exe
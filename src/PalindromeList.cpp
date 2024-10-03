#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head)
{
    vector<ListNode*> nodes;

    ListNode* current = head;

    while(current)
    {
        nodes.push_back(current);
        current = current->next;
    }

    int n = nodes.size();

    int left = 0;
    int right = n - 1;

    while(left < right)
    {
        if(left == right)
        {
            return true;
        }

        if(nodes[left]->val != nodes[right]->val)
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main()
{
    ListNode* a = new ListNode();
    ListNode* b = new ListNode();
    ListNode* c = new ListNode();
    ListNode* d = new ListNode();

    a->next = b;
    b->next = c;


    a->val = 1;
    b->val = 0;
    c->val = 1;


    bool asfd = isPalindrome(a);
    cout<<asfd<<endl;


    return 0;
}

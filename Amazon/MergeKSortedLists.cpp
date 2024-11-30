#include<vector>
#include<queue>

using namespace std;

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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        auto sorting_lambda = [](ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(sorting_lambda)> q(sorting_lambda);
        
        for(auto list : lists)
        {
            if(list) q.push(list);
        }

        ListNode* head = nullptr;
        
        if(!q.empty())
        {
            auto top = q.top();
            q.pop();
            if(top->next) q.push(top->next);

            head = top;
        }

        ListNode* current = head;

        while(!q.empty())
        {
            auto top = q.top();
            q.pop();
            if(top->next) q.push(top->next);    
        
            current->next = top;
            current = current->next;    
        }

        return head;
    }
};
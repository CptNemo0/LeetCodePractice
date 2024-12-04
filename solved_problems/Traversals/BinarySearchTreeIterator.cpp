#include "BinaryTree.h"
#include <stack>
#include <unordered_set>

struct LinkedListNode
{
    int val;
    LinkedListNode* next;
};

class BSTIterator
{
public:

    LinkedListNode* ll_head;
    LinkedListNode* current;

    void dfs(TreeNode* node)
    {
        if(!node) return;
        dfs(node->left);
        current->next = new LinkedListNode(node->val);
        current = current->next;
        dfs(node->right);
    }

    BSTIterator(TreeNode* root) 
    {
        ll_head = new LinkedListNode(-1);
        current = ll_head;
        dfs(root);
    }

    int next() 
    {
        ll_head = ll_head->next;
        return ll_head->val;
    }
    
    bool hasNext() 
    {
        return (ll_head->next);
    }
};
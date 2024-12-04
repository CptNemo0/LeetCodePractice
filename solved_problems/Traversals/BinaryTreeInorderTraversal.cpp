#include "BinaryTree.h"
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    vector<int> return_value;

    void dfs(TreeNode* node)
    {
        if(!node) return;
        dfs(node->left);
        return_value.push_back(node->val);
        dfs(node->right);
    }

    void dfs_stack(TreeNode* root)
    {
        if(!root) return;
        unordered_set<TreeNode*> visited;
        visited.insert(nullptr);
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty())
        {
            auto top = s.top();
            
            if(!visited.contains(top->left)) 
            {
                if(top->left)
                {
                    s.push(top->left);
                    continue;
                } 
                
            }
            return_value.push_back(top->val);
            visited.insert(top);
            s.pop();
            if(top->right)
            {
                s.push(top->right);
            }
        }
    }

    vector<int> inorderTraversal(TreeNode* root) 
    {
        dfs(root);
        return return_value;
    }
};
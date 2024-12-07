#include "BinaryTree.h"
#include "../minclude.h"

class Solution 
{
public:
    vector<int> inorder;

    void dfs(TreeNode* node)
    {
        if(!node) return;
        dfs(node->left);
        inorder.push_back(node->val);
        dfs(node->right);
    }

    bool isValidBST(TreeNode* root) 
    {
        dfs(root);

        for(int i = 0 ; i < inorder.size() - 1; i++)
        {
            if(inorder[i] >= inorder[i + 1]) return false;
        }
        return true;
    }
};
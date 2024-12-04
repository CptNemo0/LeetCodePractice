#include "BinaryTree.h"
#include <vector>

using namespace std;

class Solution 
{
public:
    TreeNode* current;

    void dfs(TreeNode* node)
    {
        if(!node) return;
        dfs(node->left);
        current->right = new TreeNode(node->val);
        current = current->right;
        dfs(node->right);
    }

    TreeNode* increasingBST(TreeNode* root) 
    {
        TreeNode* dummy = new TreeNode(-1);
        current = dummy;
        dfs(root);
        return dummy->right;
    }
};
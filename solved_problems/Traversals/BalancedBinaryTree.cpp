#include "BinaryTree.h"
#include <iostream>

class Solution 
{
public:

    bool return_value = true;

    int dfs(TreeNode* node, int depth)
    {
        if(!node) return depth - 1;
        int left_depth = dfs(node->left, depth + 1);
        int right_depth = dfs(node->right, depth + 1);
        int max_depth = std::max(left_depth, right_depth);

        if(abs(left_depth - right_depth) > 1)
        {
            return_value = false;
        }

        return max_depth;
    }

    bool isBalanced(TreeNode* root) 
    {
        dfs(root, 0);
        return return_value;
    }
};
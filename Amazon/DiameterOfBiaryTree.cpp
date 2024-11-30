#include<iostream>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    int result = 0;

    int dfs(TreeNode* current)
    {
        if(!current)
        {
            return 0;
        }

        auto left = dfs(current->left);
        auto right = dfs(current->right);

        int local_result = left + right;
        result = std::max(local_result, result);

        return std::max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        dfs(root);
        return result;
    }
};

int main()
{
    return 0;
}
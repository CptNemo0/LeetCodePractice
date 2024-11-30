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

int max_value = INT32_MIN;
int min_value = INT32_MAX;

void dfs(TreeNode* node, int depth)
{
    if(!node) return;

    max_value = std::max(node->val, max_value);
    min_value = std::min(node->val, min_value);

    dfs(node->left, depth + 1);
    dfs(node->right, depth + 1);
}

int diameterOfBinaryTree(TreeNode* root) 
{
    dfs(root);
    return max_value - min_value;
}

int main()
{
    return 0;
}
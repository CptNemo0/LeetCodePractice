#include<iostream>
#include<stack>
#include<set>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(int& difference, TreeNode* previous, TreeNode* node)
{
    if(!node) return;

    dfs(difference, previous, node->left);
    if(previous)
    {
        int local_difference = std::abs(node->val - previous->val);
        difference = std::min(local_difference, difference);
    }
    previous = node;
    dfs(difference, previous, node->right);
}

int getMinimumDifference(TreeNode* root)
{
    int difference = INT32_MAX;
    TreeNode* previous = nullptr;
    dfs(difference, previous, root);
    return difference;
}

int main()
{
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(6);

    d->left = b;
    d->right = e;

    b->left = a;
    b->right = c;

    getMinimumDifference(d);

    return 0;
}
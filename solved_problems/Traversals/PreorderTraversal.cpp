#include "BinaryTree.h"
#include<vector>

using namespace std;
// Preorder is DFS
class Solution {
public:

    vector<int> return_value;

    void dfs(TreeNode* node)
    {
        return_value.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }

    vector<int> preorderTraversal(TreeNode* root) 
    {
        dfs(root);
        return return_value;
    }
};
int main()
{
    auto tree = InitBT();
}
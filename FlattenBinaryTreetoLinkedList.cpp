#include <iostream>
#include <unordered_set>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void flatten(TreeNode* root)
{
    if(root == nullptr)
    {
        return;
    }

    if(root->left == nullptr && root->right == nullptr)
    {
        return;
    }

    auto most_right = [](TreeNode* node)
    {
        TreeNode* current = node;

        while(current->right != nullptr)
        {
            current = current->right;
        }

        return current;
    };

    TreeNode* current = root;

    while(current)
    {
        if(current->left != nullptr)
        {
            auto attachment_node = most_right(current->left);

            attachment_node->right = current->right;
            current->right = current->left;
            current->left = nullptr;
        }
        current = current->right;
    }
}

int main()
{    
    return 0;
}
#include "minclude.h"
#include "Traversals/BinaryTree.h"

class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        queue<TreeNode*> qu;
        qu.push(root);

        while(!qu.empty())
        {
            auto current = qu.front();
            qu.pop();
            if(!current) continue;
            if(current == q || current == p) return current;
            if(current->left == p || current->left == q || current->right == p || current->right == q) return current;

            qu.push(current->left);
            qu.push(current->right);
        }

        return nullptr;
    }
};

int main()
{

}
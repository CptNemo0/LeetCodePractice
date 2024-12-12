#include "minclude.h"
#include "Traversals/BinaryTree.h"

class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root) return nullptr;
        if(p->val > root->val && q->val < root->val)   return root;
        if(p->val < root->val && q->val > root->val)   return root;
        if(root->val == q->val || root->val == p->val) return root;

        if(p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        return lowestCommonAncestor(root->right, p, q);
    }
};

int main()
{

}
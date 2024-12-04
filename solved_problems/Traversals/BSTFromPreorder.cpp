#include <vector>
#include "BinaryTree.h"
#include <stack>
#include <iostream>
using namespace std;

class Solution 
{
public:

    TreeNode* func(vector<int>& preorder, int target, int rb)
    {
        cout<<"target: "<<target<<" rb: "<<rb;
        TreeNode* root = new TreeNode(preorder[target]);
        
        int left = -1;
        int right = -1;

        for(int i = target + 1 ; i < rb && i < preorder.size(); i++)
        {
            if(left == -1)
            {
                if(preorder[target] > preorder[i]) left = i;
            }

            if(right == -1)
            {
                if(preorder[target] < preorder[i]) right = i;
            }
        }
        cout<<" left: "<<left<<" right: "<<right<<endl;
        if(left != -1)
        {
            if(right != -1)
            {
                root->left = func(preorder, left, right);
            } 
            else
            {
                root->left = func(preorder, left, rb);
            }
            
        }
        if(right != -1) root->right = func(preorder, right, rb);
        
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        return func(preorder, 0, preorder.size());
    }
};
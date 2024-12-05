#include "minclude.h"
#include "Traversals/BinaryTree.h"

class Solution 
{
public:

    unordered_set<TreeNode*> return_value;
    unordered_set<int> to_delete_set;

    void dfs(TreeNode* node)
    {
        if(!node) return;

        TreeNode* left = node->left;
        TreeNode* right = node->right;

        if(node->left && to_delete_set.contains(node->left->val))
        {
            node->left = nullptr;
        }

        if(node->right && to_delete_set.contains(node->right->val))
        {
            node->right = nullptr;
        }

        cout<<"node->val: "<<node->val<<endl;
        if(to_delete_set.contains(node->val))
        {
            if(auto search = return_value.find(node); search != return_value.end())
            {
                return_value.erase(search);
                cout<<"erasing from return_value: "<<node->val<<endl;
            }

            if(left)
            {
                return_value.insert(left);
                cout<<"inserting to return_value: "<<left->val<<endl;
            }
            if(right)
            {
                return_value.insert(right);
                cout<<"inserting to return_value: "<<right->val<<endl;
            }
        }

        dfs(left);
        dfs(right);
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        to_delete_set = unordered_set<int>(to_delete.begin(), to_delete.end());
        return_value.insert(root);
        dfs(root);

        return{return_value.begin(), return_value.end()};
    }
};

int main()
{
    auto root = InitBT();
    Solution s {};
    vector<int> a {3, 5};
    auto result =  s.delNodes(root, a);
    for(auto& e : result)
    {
        cout<<e->val<<endl;
    }
}
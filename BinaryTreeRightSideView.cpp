#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> rightSideView(TreeNode* root) 
{
    if(root == nullptr)
    {
        return {};   
    }

    if(root->left == nullptr && root->right == nullptr)
    {
        return {root->val};
    }

    vector<int> return_value;
   
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        
        for(int i = 0; i < size ; i++)
        {
            auto& current = q.front();
            q.pop();
            
            if(i == size - 1)
            {
                return_value.push_back(current->val)
            }

            if(current->left)
            {
                q.push(current->left);
            }

            if(current->right)
            {
                q.push(current->right);
            }
        }
    }

    return return_value;
}

int main()
{
    TreeNode e(4);
    TreeNode c(3, nullptr, &e);

    TreeNode d(5);
    TreeNode b (2, nullptr, &d);

    TreeNode a(1, &b, &c);

    auto asa  = rightSideView(&a);

    for(auto z : asa)
    {
        cout<<z<<endl;
    }
}

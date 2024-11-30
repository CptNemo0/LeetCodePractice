#include<vector>
#include<queue>

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

class Solution 
{
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        if(!root) return {};

        vector<int> return_value;
        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty())
        {
            int n = static_cast<int>(nodes.size());
            for(int i = 0 ; i < n ; i++)
            {
                auto current = nodes.front();
                nodes.pop();
                if(i + 1 == n)
                {
                    return_value.push_back(current->val);
                }

                if(current->left) nodes.push(current->left);
                if(current->right) nodes.push(current->right);
            }
        }

        return return_value;
    }
};

int main()
{
    return 0;
}
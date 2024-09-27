#include <queue>

using  namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool helper(TreeNode* q, TreeNode* p)
{
if(!q && !p)
    {
        return true;
    }

    if(!q && p)
    {
        return false;
    }

    if(q && !p)
    {
        return false;
    }

    if(q->val != p->val)
    {
        return false;
    }

    else
    {
        return helper(q->right, p->left) && helper(q->left, p->right);
    }
}

bool isSymmetric(TreeNode* root)
{
    return helper(root->left, root->right);
}

int main()
{

}

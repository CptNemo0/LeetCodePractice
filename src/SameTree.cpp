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

bool isSameTree(TreeNode* p, TreeNode* q)
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
        return isSameTree(q->left, p->left) && isSameTree(q->right, p->right);
    }
}

int main()
{

}

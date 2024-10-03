struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root)
{
    if(!root)
    {
        return root;
    }

    TreeNode* left = root->left;
    TreeNode* right = root->right;

    if(left)
    {
        left = invertTree(left);
    }

    if(right)
    {
        right = invertTree(right);
    }

    root->left = right;
    root->right = left;

    return root;
}

int main()
{

}

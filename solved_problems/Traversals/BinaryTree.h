struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

inline TreeNode* InitBT()
{
    TreeNode* root = new TreeNode(1);

    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(3);

    TreeNode* lleft = new TreeNode(4);
    TreeNode* lright = new TreeNode(5);

    TreeNode* rleft = new TreeNode(6);
    TreeNode* rright = new TreeNode(7);

    root->left = left;
    root->right = right;

    left->left = lleft;
    left->right = lright;

    right->left = rleft;
    right->right = rright;

    return root;
}
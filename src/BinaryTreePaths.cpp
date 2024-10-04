#include <iterator>
#include <string>
#include <stack>
#include <system_error>
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

vector<string> binaryTreePaths(TreeNode* root)
{
    if(root == nullptr)
    {
        return {};
    }

    vector<string> return_value;
    stack<string> strings;
    stack<TreeNode*> nodes;

    nodes.push(root);
    strings.push(to_string(root->val));

    while(!nodes.empty())
    {
        auto current_node = nodes.top();
        auto current_string = strings.top();

        if(!current_node->left && !current_node->right)
        {
            return_value.push_back(current_string);
            nodes.pop();
            strings.pop();
        }
    }
}

int main()
{

}

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

        nodes.pop();
        strings.pop();

        if(!current_node->left && !current_node->right)
        {
            return_value.push_back(current_string);
            continue;
        }

        if(current_node->right)
        {
            nodes.push(current_node->right);
            strings.push(current_string + "->" + to_string(current_node->right->val));
        }

        if(current_node->left)
        {
            nodes.push(current_node->left);
            strings.push(current_string + "->" +to_string(current_node->left->val));
        }
    }

    return return_value;
}

int main()
{

}

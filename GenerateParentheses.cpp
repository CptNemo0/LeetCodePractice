#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    string value;
    int open;
    int closed;

    Node* left;
    Node* right;
};

vector<string> generateParenthesis(int n) 
{
    vector<string> return_value;

    Node* head = new Node();
    head->value = "";
    head->open = 0;
    head->closed = 0;
    head->left = nullptr;
    head->right = nullptr;
    stack<Node*> nodes;
    nodes.push(head);

    while(!nodes.empty())
    {
        auto current = nodes.top();
        if(current->open == n && current->closed == n)
        {
            return_value.push_back(current->value);
            nodes.pop();
            continue;
        }

        if(current->left == nullptr)
        {
            if(current->open < n)
            {
                Node* left_node = new Node();
                left_node->value = current->value + "(";
                left_node->open = current->open + 1;
                left_node->closed = current->closed;
                left_node->left = nullptr;
                left_node->right = nullptr;

                current->left = left_node;
                nodes.push(left_node);
                continue;
            }
        }
        if(current->right == nullptr)
        {
            if(current->closed < current->open)
            {
                Node* right_node = new Node();
                right_node->value = current->value + ")";
                right_node->open = current->open;
                right_node->closed = current->closed + 1;
                right_node->left = nullptr;
                right_node->right = nullptr;

                current->right = right_node;
                nodes.push(right_node);
                continue;
            }
        }
        nodes.pop();
    }
    return return_value;
}

int main()
{
    auto a = generateParenthesis(3);

    for(auto b : a)
    {
        std::cout<<b<<std::endl;
    } 
}
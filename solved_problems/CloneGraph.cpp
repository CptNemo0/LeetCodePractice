#include "minclude.h"

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

void Log(Node* node)
{
    cout<<"val: "<<node->val<<"\n";
    cout<<"neighbors: \n";
    for(auto& n : node->neighbors)
    {
        cout<<"\t"<<n->val<<endl;
    }
}

class Solution 
{
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<int, Node*> new_nodes;
        int start_value = node->val;

        queue<Node*> q;
        q.push(node);
        new_nodes[start_value] = new Node(start_value);
        
        while(!q.empty())
        {
            auto current = q.front();
            q.pop();
            for(int i = 0 ; i < current->neighbors.size() ; i++)
            {
                if(!new_nodes.contains(current->neighbors[i]->val))
                {
                    new_nodes[current->neighbors[i]->val] = new Node(current->neighbors[i]->val);
                    q.push(current->neighbors[i]);
                }
                new_nodes[current->val]->neighbors.push_back(new_nodes[current->neighbors[i]->val]);
            }
        }

        /*for(const auto& [key, value] : new_nodes)
        {
            Log(value);
        }*/

        return new_nodes[start_value];
    }
};

int main()
{
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    Node* five = new Node(5);

    one->neighbors.push_back(two);
    one->neighbors.push_back(four);

    two->neighbors.push_back(one);
    two->neighbors.push_back(three);

    three->neighbors.push_back(two);
    three->neighbors.push_back(four);

    four->neighbors.push_back(one);
    four->neighbors.push_back(three);
    four->neighbors.push_back(five);

    five->neighbors.push_back(four);

    Solution s {};
    s.cloneGraph(one);

    return 0;
}
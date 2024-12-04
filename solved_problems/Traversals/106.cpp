#include "BinaryTree.h"
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution 
{
public:
    unordered_map<int, int> inorder_map;
    deque<int> postorder_q;

    TreeNode* solve(int left, int right)
    {
        if(postorder_q.empty()) return nullptr;
        if(left == right) return nullptr;

        int val = postorder_q.back();
        postorder_q.pop_back();

        int idx = inorder_map[val];
        if(idx < left || idx >= right) return nullptr;

        auto right_node = solve(idx + 1, right);
        auto left_node = solve(left, idx);

        TreeNode* node = new TreeNode(val, left_node, right_node);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        
        postorder_q = deque<int>(postorder.begin(), postorder.end());
        for(int i = 0 ; i < inorder.size() ; i++)
        {
            inorder_map[inorder[i]] = i;
        }
        return solve(0, postorder.size());
    }
};
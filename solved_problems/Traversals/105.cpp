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

        int val = postorder_q.front();
        postorder_q.pop_front();

        int idx = inorder_map[val];
        if(idx < left || idx >= right) return nullptr;

        TreeNode* node = new TreeNode(
            val,
            solve(left, idx),
            solve(idx + 1, right)
        );

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        
        postorder_q = deque<int>(preorder.begin(), preorder.end());
        for(int i = 0 ; i < inorder.size() ; i++)
        {
            inorder_map[inorder[i]] = i;
        }
        return solve(0, preorder.size());
    }
};
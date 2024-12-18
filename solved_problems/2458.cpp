#include "minclude.h"

class Solution 
{
public:
    vector<vector<int>> levels;
    unordered_map<int, int> size_below;
    unordered_map<int, int> num_depth;
    
    int max_depth = 0;
    vector<int> return_value;

    int dfs(TreeNode* node, int depth)
    {
        if(!node) return -1;

        if(depth >= levels.size())
        {
            levels.push_back({});
        }
        levels[depth].push_back(node->val);
        num_depth[node->val] = depth;
        size_below[node->val] = 1 + max(dfs(node->left, depth + 1), dfs(node->right, depth + 1));
        return size_below[node->val];
    }

    void remove_query(int query)
    {
        int depth = num_depth[query];

        int m = -1;
        if(levels[depth].size() == 1)
        {
            return_value.push_back(depth - 1);
            return;
        }
        
        for(auto& num : levels[depth])
        {
            if(num == query) continue;
            m = max(m, size_below[num]);
        }
        
        return_value.push_back(m + depth);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) 
    {
        dfs(root, 0);
        for(auto& query : queries)
        {
            remove_query(query);
        }
        return return_value;
    }
};

int main()
{
    vector<int> a {6, 3};
    auto root = InitBT();
    Solution sol {};
    sol.dfs(root, 0);
    for(const auto& [key, val] : sol.size_below)
    {
        cout<<"key: "<<key<<" value: "<<val<<endl;
    }
}
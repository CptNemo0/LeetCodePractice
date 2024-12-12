#include "minclude.h"

class Solution 
{
public:
    vector<vector<int>> return_value;
    unordered_set<int> visited;

    void dfs(vector<int>& input, const vector<int>& nums)
    {
        if(input.size() == nums.size())
        {
            vector<int> output;
            for(auto& n : input)
            {
                output.emplace_back(nums[n]);
            }
            return_value.push_back(output);
            return;
        }
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(visited.contains(i)) continue;

            visited.insert(i);
            input.push_back(i);
            dfs(input, nums);
            visited.erase(visited.find(i));
            input.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> input;
        input.reserve(nums.size());
        for(int i = 0 ; i < nums.size() ; i++)
        {
            visited.clear();
            input.clear();    
            input.emplace_back(i);
            visited.insert(i);
            dfs(input, nums);
        } 

        return return_value;       
    }
};

int main()
{
    
}
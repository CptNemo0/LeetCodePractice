#include "minclude.h"

class Solution 
{
public:
    vector<vector<int>> return_value;

    void subsets_for_idx(int idx, vector<int>& input, vector<int>& nums)
    {
        if(idx >= nums.size()) return;
        
        for(int i = idx ; i < nums.size() ; i++)
        {
            input.push_back(nums[i]);
            return_value.push_back(input);
            subsets_for_idx(i + 1, input, nums);
            input.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        return_value.push_back({});
        for(int i = 0 ; i < nums.size() ; i++)
        {
            vector<int> input {nums[i]};
            return_value.push_back(input);
            subsets_for_idx(i + 1, input, nums);
        }
        return return_value;
    }
};

int main()
{
    Solution sol {};
    vector<int> input {1, 2, 3};
    sol.subsets(input);
}
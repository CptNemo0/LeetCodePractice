#include<vector>
#include<iostream>

using namespace std;

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int current_sum = 0;
        int best_sum = INT_MIN;

        for(auto& n : nums)
        {
            current_sum = max(n, current_sum);
            best_sum    = max(current_sum, best_sum);
        }        

        return best_sum;
    }
};
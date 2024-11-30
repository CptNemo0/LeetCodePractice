#include<vector>

using namespace std;

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        if(!nums.size()) return INT32_MIN;

        int max_sum = nums[0];
        int previous_sum = 0;

        for(const auto& n : nums)
        {
            previous_sum = max(previous_sum, 0); // check if previous sums add up to positive number, 
                                                 // if not zero it in order to not diminish current sum
            int current_sum = previous_sum + n;  // calculate current_sum, that is at least equal to n
            max_sum = max(current_sum, max_sum); // update max_sum
            previous_sum = current_sum;          // update previous_sum
        }

        return max_sum;
    }
};
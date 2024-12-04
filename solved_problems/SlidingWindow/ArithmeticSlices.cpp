#include<vector>

using namespace std;

class Solution 
{
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        auto diffs = [&nums](int i)
        {
            return nums[i] - nums[i + 1];
        };

        int left = 0;
        int right = 1;
        int return_value = 0;

        while(right <= nums.size() - 1)
        {
            if(right == nums.size() - 1|| diffs(left) != diffs(right))
            {
                int len = right - left;
                if(len == 1)
                {
                    left = right;
                    right++;
                    continue;
                }
                
                int n = len - 1;
                int subarrays = (n + n * n) / 2;
                return_value += subarrays;
                left = right;
                right++;
            }
            else if (diffs(left) == diffs(right))
            {
                right++;
            }
        }

        return return_value;
    }
};
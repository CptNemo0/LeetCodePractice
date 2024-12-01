#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution 
{
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        vector<int> diffs;

        for(int i = 0; i < nums.size() - 1 ; i++)
        {
            diffs.push_back(nums[i] - nums[i + 1]);
        }


        int left = 0;
        int right = 0;
        int return_value = 0;

        while(right <= diffs.size())
        {
            if(left == right)
            {
                right++;
                continue;
            }

            if(diffs[left] != diffs[right] || right == diffs.size())
            {
                int len = right - left;
                if(len == 1)
                {
                    left = right;
                    continue;
                }
                
                int n = len - 1;
                int subarrays = (n + n * n) / 2;
                return_value += subarrays;
                left = right;
            }
            else if (diffs[left] == diffs[right])
            {
                right++;
            }
        }

        return return_value;
    }
};
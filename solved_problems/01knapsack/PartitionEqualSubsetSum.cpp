#include "minclude.h"

class Solution 
{
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for(auto& num : nums)
        {
            sum += num;
        }     
        if(sum & 1) return false;

        int target = sum / 2;
        unordered_set<int> set;
        set.insert(0);

        for(int i = nums.size() ; i > -1 ; i--)
        {
            for(auto& n : set)
            {
                if(n + nums[i] == target) return true;
                set.insert(n + nums[i]);
            }
        }

        return false;
    }
};

int main()
{
    return 0;
}
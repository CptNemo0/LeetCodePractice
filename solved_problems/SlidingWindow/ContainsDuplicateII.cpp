#include<vector>
#include<unordered_set>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_set<int> set;
        int left = 0;
        int right = 0;

        while(right < nums.size())
        {
            if(right - left > k)
            {
                set.erase(set.find(nums[left]));
                left++;
            }

            if(set.contains(nums[right]))
            {
                return true;
            }
            set.insert(nums[right]);
            right++;
        }

        return false;

    }
};
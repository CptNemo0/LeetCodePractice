#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        switch (n)
        {
        case 0:
            return 0;
        case 1:
            return nums[0];
        case 2:
            return std::max(nums[0], nums[1]);
        case 3:
            return std::max(nums[0] + nums[2], nums[1]);
        default:

            nums[nums.size() - 3] += nums[nums.size() - 1];
            int ptr = nums.size() - 4;

            while(ptr > -1)
            {
                int left = nums[ptr + 2] + nums[ptr];
                int right = nums[ptr + 3] + nums[ptr];

                nums[ptr] = std::max(left, right);

                ptr--;
            }

            return std::max(nums[0], nums[1]);

            break;
        }
    }
};

int main()
{
    auto s = Solution();
    vector<int> v {2,7,9,3,1};
    s.rob(v);

}
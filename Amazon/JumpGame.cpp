#include<vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums) 
    {
        if(nums.size() == 1) return true;
        int demand = 1;
        int ptr = nums.size() - 2;

        while(ptr > 0)
        {
            if(demand > nums[ptr])
            {
                demand++;
            }
            else
            {
                demand = 1;
            }

            ptr--;
        }

        return demand <= nums[0];
    }
};

int main()
{
    
}
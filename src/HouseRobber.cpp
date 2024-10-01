#include<vector>

using namespace std;

int rob(vector<int>& nums)
{
    if(!nums.size())
    {
        return 0;
    }

    if(nums.size() == 1)
    {
        return nums[0];
    }

    if(nums.size() == 2)
    {
        return max(nums[0], nums[1]);
    }

    if(nums.size() >= 3)
    {
        int memory_1 = 0;
        int memory_2 = 0;

        for(int i =  nums.size() - 3 ; i > -1; i--)
        {
            int current_value = max(nums[i] + memory_1, memory_2);
            memory_1 = memory_2;
            memory_2 = current_value;
        }
    }



    return memory_2;
}

int main()
{
    return 0;
}

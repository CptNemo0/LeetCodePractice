#include<vector>

using namespace std;

int my_max(int a, int b)
{
    int difference = a - b;
    int b_greater = (difference >> 31) & 1;
    return a - difference * b_greater;
}

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

    int memory_1 = 0;
    int memory_2 = 0;

    for(int i = 0 ; i < nums.size() ; i++)
    {
        int current_value = my_max(nums[i] + memory_1, memory_2);
        memory_1 = memory_2;
        memory_2 = current_value;
    }

    return memory_2;
}

int main()
{
    return 0;
}

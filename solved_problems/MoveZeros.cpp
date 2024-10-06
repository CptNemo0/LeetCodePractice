#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void moveZeroes(vector<int>& nums)
{
    if(nums.size() == 0)
    {
        return;
    }

    int left = 0;
    int right = nums.size() - 1;

    while(left < right)
    {
        if(nums[left] == 0)
        {
            move(nums.begin() + left + 1, nums.begin() + right + 1, nums.begin() + left);
            nums[right] = 0;
            right--;
        }
        else
        {
            left++;
        }
    }
}

int main()
{

}

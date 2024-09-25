#include <iostream>
#include <vector>

using namespace std;

int binary_search(int target, vector<int>& nums, int left, int right)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if(target == nums[mid])
        {
            return mid;
        }

        if(target > nums[mid])
        {
            return binary_search(target, nums, mid + 1, right);
        }        

        if(target < nums[mid])
        {
            return binary_search(target, nums, left, mid - 1);
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) 
{
    // find pivot

    int n = static_cast<int>(nums.size());

    if(n == 1)
    {
        if(target == nums[0])
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    int pivot_index = -1;
    for(int i = 0 ; i < n - 1; i++)
    {
        if(nums[i] == target)
        {
            return i;
        }
        if(nums[i] > nums[i + 1])
        {
            pivot_index = i;
            break;
        }
    }

    return binary_search(target, nums, pivot_index + 1, n - 1);

   
}

int main()
{
    cout<<"GO\n";
    vector<int> nums { 4,5,6,7,0,1,2};

    int left = 0;
    int right = static_cast<int>(nums.size() - 1);

    cout<<search(nums, 0)<<endl;

    return 0;
}
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:

    int binary_search(vector<int>& nums, int target, int left, int right)
    {
        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(nums[mid] == target)
            {
                return mid;
            }

            if(nums[mid] > target)
            {
                right = mid - 1;
                continue;
            }

            left = mid + 1;
        }

        return -1;
    }

    int solve(vector<int>& nums, int target, int left, int right)
    {
        if(nums[left] < nums[right])
        {
            return binary_search(nums, target, left, right);
        }

        int mid = left + (right - left) / 2;

        if(nums[mid] == target) return mid;

        if(mid != 0 && mid != nums.size() - 1)
        {
            if(nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1])
            {
                //w srodku 
                if(nums[left] < nums[mid])
                {
                    if(nums[left] <= target && target <= nums[mid]) 
                    {
                        return binary_search(nums, target, left, mid);
                    }

                    return solve(nums, target, mid, right);
                }

                if(nums[mid] < nums[right])
                {
                    if(nums[mid] <= target && target <= nums[right])
                    {
                        return binary_search(nums, target, mid, right);
                    }

                    return solve(nums, target, left, mid);
                }
            }

            if(nums[mid - 1] <  nums[mid] &&  nums[mid] > nums[mid +1])
            {
                if(nums[left] <= target && target <= nums[mid]) 
                {
                    return binary_search(nums, target, left, mid);
                }

                return binary_search(nums, target, mid + 1, right);
            }

            if(nums[mid - 1 >  nums[mid] &&  nums[mid] < nums[mid + 1]])
            {
                if(nums[mid] <= target && target <= nums[right])
                    {
                        return binary_search(nums, target, mid, right);
                    }

                    return binary_search(nums, target, left, mid - 1);
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;
        
        return solve(nums, target, left, right);
    }
};

int main()
{

}
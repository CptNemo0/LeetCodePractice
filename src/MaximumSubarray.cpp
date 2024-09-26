#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) 
{
    int n = static_cast<int>(nums.size());

    if(n == 1)
    {
        return nums[0];
    }

    int sum = 0;
    int max_sum = INT_MIN;

    for(auto number : nums)
    {
        sum += number;
        
        max_sum = max(sum, max_sum);

        if(sum < 0)
        {
            sum = 0;
        }
    }

    return max_sum;

}

int main()
{

}
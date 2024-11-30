#include<vector>
#include<unordered_set>
#include<iostream>

using namespace std;

class Solution 
{
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        if(!nums.size()) return INT32_MIN;

        int max_sum = nums[0];
        int min_sum = nums[0];

        int previous_sum_max = 0;
        int previous_sum_min = 0;

        int accumulation = 0;

        for(const auto& n : nums)
        {
            accumulation += n;

            previous_sum_max = max(previous_sum_max, 0);
            previous_sum_min = min(previous_sum_min, 0);

            int current_sum_max = previous_sum_max + n;
            int current_sum_min = previous_sum_min + n;
              
            max_sum = max(current_sum_max, max_sum);
            min_sum = min(current_sum_min, min_sum);

            previous_sum_max = current_sum_max;
            previous_sum_min = current_sum_min;
        }

        cout<<"min_sum: "<<min_sum<<endl;
        cout<<"max_sum: "<<max_sum<<endl;
        cout<<"accumulation: "<<accumulation<<endl;

        return max(max_sum, accumulation - min_sum);
    }
};

int main()
{
    Solution s {};
    vector<int> a {3, -1, -2, 2, 0, -1, 2, 3};
    cout<<s.maxSubarraySumCircular(a);
}
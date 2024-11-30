#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> return_value;
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            cout<<"i: "<<i<<" nums["<<i<<"]: "<<nums[i]<<"\n";

            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                cout<<"\tright: "<<right<<" nums["<<right<<"]: "<<nums[right]<<"\n";
                cout<<"\tleft: "<<left<<" nums["<<left<<"]: "<<nums[left]<<"\n";
                cout<<"\tsum: "<<sum<<"\n\n";

                if(sum > 0)
                {
                    right--;
                    
                    continue;
                }

                if(sum < 0)
                {
                    left++;
                    
                    continue;
                }

                return_value.push_back({nums[i], nums[left], nums[right]});
                left++;
                while(left + 1 < right && nums[left - 1] == nums[left])
                {
                    left++;
                }
            }
        }
        return return_value;
    }
};

int main()
{
    Solution s {};

    vector<int> v {-1,0,1,2,-1,-4};

    s.threeSum(v);

    return 0;
}
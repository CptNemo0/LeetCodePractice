#include <unordered_map>
#include <algorithm>
#include <vector>
#include<iostream>

using  namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    unordered_map<int , vector<int>> num_idx;

    for(int i = 0 ; i < nums.size(); i++)
    {
        cout<<"i: "<<i<<", nums["<<i<<"]: "<<nums[i]<<endl;
        auto search = num_idx.find(nums[i]);
        if( search != num_idx.end())
        {
            auto& vec = num_idx[nums[i]];

            for(auto idx : vec)
            {
                cout<<"\tidx: "<<idx<<endl;
                int result = abs(i - idx);
                cout<<"\tresult: "<<result<<endl;
                if(result <= k)
                {
                    return true;
                }
            }

            vec.push_back(i);
        }
        else
        {
            num_idx.insert({nums[i], {i}});
        }
    }

    return false;
}

int main()
{
    vector<int> a {1,0,1,1};
    cout<<containsNearbyDuplicate(a, 1);
}

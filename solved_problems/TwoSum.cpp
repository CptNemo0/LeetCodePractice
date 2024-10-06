#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
    vector<int> return_value;
    map<int, int> hash_map;
    int n = static_cast<int>(nums.size());

    for(int i = 0 ; i < n ; i++)
    {
        int complement = target - nums[i];

        if(hash_map.count(complement))
        {
            return_value.push_back(hash_map[complement]);
            return_value.push_back(i); 
        }
        else
        {
            hash_map[nums[i]] = i;
        }
    }

    return return_value;
}

int main()
{
    return 0;
}
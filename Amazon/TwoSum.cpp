#include<vector>
#include<unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{              //rest, idx
    unordered_map<int, int> map;
    vector<int> return_value = {-1, -1};
    int n = nums.size();

    for(int i = 0 ; i < n ; i++)
    {
        if(auto search = map.find(nums[i]) ; search != map.end())
        {
            return_value[0] = i;
            return_value[1] = map[nums[i]];
            break;
        }
        int rest = target - nums[i];
        map.emplace(rest, i);
    }
    return return_value;
}

int main()
{
    return 0;
}
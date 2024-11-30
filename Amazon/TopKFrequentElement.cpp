#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int, int> map;
    
        vector<int> return_value;
        int max_count = 0;

        for(auto& n : nums)
        {
            map[n]++;
            max_count = max(max_count, map[n]);
        }

        vector<vector<int>> buckets (max_count + 1);

        for(const auto& [key, val] : map)
        {
            buckets[val].push_back(key);
        }

        for(int i = max_count ; i > 0 && return_value.size() < k ; i--)
        {
            for(auto val : buckets[i])
            {
                return_value.push_back(val);
                if(return_value.size() == k) 
                {
                    break;
                }
            }
        }

        return return_value;
    }
};
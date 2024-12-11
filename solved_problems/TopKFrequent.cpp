#include "minclude.h"

class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        auto lambda = [](pair<int, int>& x, pair<int, int>& y)
        {
            return x.second < y.second;
        };

        unordered_map<int, int> counts;
        vector<int> return_value;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(lambda)> q;
        
        for(auto& n : nums)
        {
            counts[n]++;
        }

        for(auto& p : counts)
        {
            q.push(p);
        }

        
        while(return_value.size() < k)
        {
            const auto [key, val] = q.top();
            q.pop();
            return_value.push_back(key);
        }
      
        return return_value;
    }
};

int main()
{
    vector<int> a {1,1,1,2,2,3,1,7,8,9,10,11,11,1,11};
    Solution sol{};
    sol.topKFrequent(a, 2);
}
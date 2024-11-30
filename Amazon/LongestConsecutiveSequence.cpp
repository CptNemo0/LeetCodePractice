#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution 
{
public:
    unordered_set<int> lookup;
    unordered_set<int> already_checked;
    unordered_map<int, int> dp;

    int solve(int n)
    {
        if(!lookup.contains(n)) return 0;

        if(already_checked.contains(n))
        {
            return dp[n];
        }
        else
        {
            already_checked.insert(n);
            dp[n] = 1 + solve(n + 1);
            return dp[n]; 
        }
    }

    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.empty()) return 0;
        int m = 1;
    
        for(auto& n : nums)
        {
            lookup.insert(n);
        }

        for(auto& n : nums)
        {
            if(already_checked.contains(n)) continue;

            already_checked.insert(n);
            dp[n] = 1 + solve(n + 1);
            m = max(m, dp[n]);
        }

        return m;
    }
};
#include "minclude.h"

class Solution 
{
public:
    vector<int> countBits(int n) 
    {
        int previous_power = 1;
        int power = 2;
        
        vector<int> dp {0, 1};

        for(int i = 2 ; i <= n ; i++)
        {
            if(i == power)
            {
                previous_power = power;
                power *= 2;
            }
            
            int diff = i - previous_power;
            dp.push_back(1 + dp[diff]);
        }

        return dp;
    }
};

int main()
{
    Solution s{};
    s.countBits(10);
}
#include<vector>
#include<iostream>

using namespace std;

class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int return_value = 0;
        int n = height.size();
        vector<int> maxl(n, 0);
        
        int m = 0;
        for(int i = 0 ; i < n ; i++)
        {
            maxl[i] = m;
            m = max(m, height[i]);
        }

        m = 0;
        for(int i = n - 1; i > -1 ; i--)
        {
            return_value += max(min(maxl[i], m) - height[i], 0);
            m = max(m, height[i]);
        }

        return return_value;
    }
};

int main()
{
    
}
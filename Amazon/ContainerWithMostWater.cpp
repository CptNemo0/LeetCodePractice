#include<vector>
#include<iostream>

using namespace std;

class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0;
        int right = height.size() - 1;
        int max_cap = 0;

        while(left < right)
        {
            max_cap = max(max_cap, (right - left) * min(height[left], height[right]));

            if(height[left] > height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return max_cap;
    }
};

int main()
{
    vector<int> h { 1,3,2,5,25,24,5 };
    Solution s {};
    s.maxArea(h);
    return 0;
}
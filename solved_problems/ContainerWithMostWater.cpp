#include "minclude.h"

class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0;
        int right = height.size() - 1;
        int max_cap = min(height[left], height[right]) * (right - left);

        while(right > left)
        {
            if(height[left] > height[right])
            {
                right--;
            }
            else
            {
                left++;
            }

            max_cap = max(min(height[left], height[right]) * (right - left), max_cap);
        }    

        return max_cap;
    }
};
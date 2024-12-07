#include "minclude.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;

        for(auto& n : nums)
        {
            switch(n)
            {
                case 0:
                zeros++;
                break;

                case 1:
                ones++;
                break;

                case 2:
                twos++;
                break;
            }
        }

        int ptr = 0;
        for(int i = zeros ; i > 0 ; i--)
        {
            nums[ptr] = 0;
            ptr++;
        }

        for(int i = ones ; i > 0 ; i--)
        {
            nums[ptr] = 1;
            ptr++;
        }

        for(int i = twos ; i > 0 ; i--)
        {
            nums[ptr] = 2;
            ptr++;
        }
    }
};
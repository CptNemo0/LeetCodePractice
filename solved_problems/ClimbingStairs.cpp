#include "minclude.h"

class Solution 
{
public:
    int climbStairs(int n) 
    {
        int left = 1;
        int right = 2;

        if(n == 1) return left;
        if(n == 2) return right;

        int return_value = 0;
        for(int i = 3 ; i <= n ; i++)
        {
            return_value = left+right;
            left = right;
            right = return_value;
        }    

        return return_value;
    }
};

int main()
{
    return 0;
}
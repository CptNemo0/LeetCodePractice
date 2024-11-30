#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int poa = 1;
        int z = 0;

        for(auto& i : nums)
        {
            if(i != 0)
            {
                poa = poa * i;
                continue;
            }
            z++;
        }
        
        poa *= (z < 2);

        for(auto& i : nums)
        {
            if(z && i)
            {
                i = 0;
            }
            else if(z && !i)
            {
                i = poa;
            }
            else if(!z)
            {
                i = poa / i;
            }
        }

        return nums;
    }
};

int main()
{
    return 0;
}
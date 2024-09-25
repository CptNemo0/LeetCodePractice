#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
        int unique_ctr = 0;
        int n = static_cast<int>(nums.size());

        
        for(int i = 0 ; i < n ; i++)
        {
            if(i == 0)
            {
                nums[unique_ctr] = nums[i];
                unique_ctr++;
                continue;
            }
            if(nums[i] != nums[i - 1])
            {
                nums[unique_ctr] = nums[i];
                unique_ctr++;
            }
        }

        return unique_ctr;
    }

int main()
{
    return 0;
}
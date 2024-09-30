#include <iostream>
#include <type_traits>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums)
{
    unordered_map<int, int> repetitions;
    int n = static_cast<int>(nums.size());
    int half = n / 2;

    for(int i = 0 ; i < n ; i++)
    {
        repetitions[nums[i]]++;

        if(repetitions[nums[i]] > half)
        {
            return nums[i];
        }
    }
    return 0;
}

int main()
{

}

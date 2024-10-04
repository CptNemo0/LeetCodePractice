#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums)
{
    int n = static_cast<int>(nums.size());
    vector<int> present (n + 1, 1);

    for(const auto& x : nums)
    {
        present[x] = 0;
    }

    int return_value = -1;

    for(int i = 0; i < n + 1 ; i++)
    {
        if(present[i])
        {
            return_value = i;
            break;
        }
    }

    return return_value;
}


int main()
{

}

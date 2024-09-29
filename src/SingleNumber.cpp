#include <vector>

using  namespace std;

int singleNumber(vector<int>& nums)
{
    int return_value = 0;
    for(auto n : nums)
    {
        return_value = return_value ^ n;
    }

    return return_value;
}

int main()
{
    return 0;
}

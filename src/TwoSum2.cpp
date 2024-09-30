#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
    int left = 0;
    int right = static_cast<int>(numbers.size()) - 1;

    while(left < right)
    {
        int sum = numbers[left] + numbers[right];

        if(sum > target)
        {
           right--;
           continue;
        }

        if(sum < target)
        {
            left++;
            continue;
        }

        if(sum == target)
        {
            break;
        }
    }
    return {left + 1, right + 1};
}

int main()
{

}

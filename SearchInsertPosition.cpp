#include <vector>
#include <iostream>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int n = static_cast<int>(nums.size());

    int low = 0;
    int high = n - 1;
    int mid  = 0;
    while(low <= high)
    {
        mid = low + ((high - low) / 2);

        cout<<"\nlow : "<<low<<endl;
        cout<<"mid : "<<mid<<endl;
        cout<<"high: "<<high<<endl;

        if(target == nums[mid])
        {
            return mid;
        }

        if(target > nums[mid])
        {
            low = mid + 1;
        }

        if(target < nums[mid])
        {
            high = mid - 1;
        }
    }

    if(target > nums[mid])
    {
        return mid + 1;
    }

    if(target < nums[mid])
    {
        if(mid == 0)
        {
            return 0;
        }

        if(target > nums[mid - 1])
        {
            return mid;
        }
        else
        {
            return mid - 1;
        }

    }
    return -1;
}

int main()
{
    vector<int> v {1,3,5, 6};

    cout<<searchInsert(v, 0);

    return 0;
}

#include <vector>
#include <algorithm>

using namespace std;

int searchInsert(vector<int>& nums, int target, int low, int high)
{
    int n = static_cast<int>(nums.size());

    int mid  = 0;
    while(low <= high)
    {
        mid = low + ((high - low) / 2);

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

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    if(m == 0)
    {
        move(nums2.begin(), nums2.end(), nums1.begin());
        return;
    }

    int last_insert_position = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int current = nums2[i];
        int insert_position = searchInsert(nums1, current, last_insert_position, m - 1);
        last_insert_position = insert_position;
        int diff = m - insert_position;

        if(diff == 0)
        {
            nums1[insert_position] = nums1[insert_position + 1];
            nums1[insert_position] = current;
            m++;
            continue;
        }

        if(diff > 0)
        {
            move(nums1.begin() + insert_position, nums1.begin() + m, nums1.begin() + insert_position + 1);
            nums1[insert_position] = current;
            m++;
            continue;
        }

        if(diff < 0)
        {
            nums1[insert_position] = current;
            m++;
            continue;
        }
    }
}

int main()
{
    vector<int> a {1,0};
    vector<int> b {2};

    merge(a, 1, b, 1);

    return 0;
}

#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> return_value;

    int n = nums1.size();
    int m = nums2.size();

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0;
    int j = 0;
    while(i < n && j < m)
    {
        if(nums1[i] == nums2[j])
        {
            return_value.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return return_value;
}

int main()
{
    return 0;
}

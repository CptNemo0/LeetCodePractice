#include<vector>
#include<unordered_set>
#include<iostream>

using namespace std;

class Solution 
{
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int left = 0;
        int right = 0;
        int return_value = 0;
        int sum = 0;

        while(right < arr.size())
        {
            sum += arr[right];
            if(right - left + 1 == k)
            {
                int avg = sum / k;
                if(avg >= threshold)
                {
                    cout<<"left: "<<arr[left]<<" right: "<<arr[right]<<" sum: "<<sum<<" avg: "<<avg<<"\n";
                    return_value++;
                } 
            }
            
            right++;
            if(right - left + 1 > k)
            {
                sum -= arr[left];
                left++;
            }
        }

        return return_value;
    }
};

int main()
{
    vector<int> v {2,2,2,2,5,5,5,8 };
    Solution s {};
    s.numOfSubarrays(v, 3, 4);
}
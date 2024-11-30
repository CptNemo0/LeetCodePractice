#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
public:
    int maxTurbulenceSize(vector<int>& arr)
    {
        if(!arr.size()) return 0;
        if(arr.size() == 1) return 1;

        vector<int> signs;
        auto get_sign = [](int a, int b)
        {
            if(a > b)  return -1;
            if(a == b) return  2;
            return 1;
        };

        int eq_ctr = 0;
        for(int i = 0; i < arr.size() - 1; i++)
        {
            int sign = get_sign(arr[i], arr[i + 1]);
            signs.push_back(sign);
            if(sign == 2) eq_ctr++;
        }

        if(eq_ctr == signs.size()) return 1;

        int left = 0;
        int right = 1;
        int longest_array = 1;

        while(right < signs.size())
        {
            if(signs[right - 1] == -signs[right])
            {
                int len = right + 1 - left;
                longest_array = max(longest_array, len);
                right++;
                continue;
            }

            left = right;
            right++;
        }
        cout<<longest_array<<endl;
        return longest_array + 1;
    }
};

int main()
{
    vector<int> a {100, 100, 100};
    Solution s {};
    s.maxTurbulenceSize(a);
}
#include<iostream>
#include<string>

using namespace std;

class Solution 
{
public:
    int maxPower(string s) 
    {
        if(s.length() == 1) return 1;

        int return_value = 0;
        int left = 0;
        int right = 0;

        while(right < s.length())
        {
            if(s[left] == s[right])
            {
                int local_len = ((right - left) + 1);
                return_value = max(local_len, return_value);
                right++;
                continue;
            }
            else
            {
                left = right;
                continue;
            }
        }

        return return_value;
    }
};
#include<unordered_map>
#include<string>
#include<iostream>

using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.empty()) return 0;
        if(s.length() == 1) return 1;
        
        int return_value = 1;

        unordered_map<char, int> fqs;

        int left = 0;
        fqs[s[left]]++;

        int right = 0;

        
        while(right < s.length())
        {
            std::cout<<"left: "<<s[left]<<" right: "<<s[right]<<" return_value: "<<return_value<<std::endl;
            if(left == right)
            {
                std::cout<<"Equal, move right\n";
                right++;
                fqs[s[right]]++;
                continue;
            }

            if(fqs[s[right]] > 1)
            {
                std::cout<<"Move left\n";
                fqs[s[left]]--;
                left++;
                continue;
            }

            return_value = max((right - left) + 1, return_value);
            right++;
            fqs[s[right]]++;
        }

        return return_value;    
    }
};

int main()
{
    Solution sol {};

    std::cout<<sol.lengthOfLongestSubstring("dvdf")<<"\n";
    return  0;
}
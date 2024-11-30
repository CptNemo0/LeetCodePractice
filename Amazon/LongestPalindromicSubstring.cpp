#include<string>
#include<unordered_map>
#include<iostream>

using namespace std;

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        if(s.empty()) return {};
        if(s.length() == 1) return s;

        int max_length = 1;
        int max_left = 0;
        
        auto main_algorithm = [s, &max_length, &max_left](int left, int right)
        {
            while(left >= 0 && right < s.length() && s[left] == s[right])
            {
                std::cout<<"left: "<<s[left]
                         <<" right: "<<s[right]
                         <<"\n";
                int local_length = (right - left) + 1;

                if(local_length > max_length)
                {
                    max_left = left;
                    max_length = local_length;
                }

                left--;
                right++;
            }
        };

        for(int i = 0; i < s.length() ; i++)
        {
            int left = i;
            int right = i;

            main_algorithm(left, right);
            right++;
            main_algorithm(left, right);
        }

        return s.substr(max_left, max_length);
    }
};

int main()
{
    Solution s {};
    std::cout<<s.longestPalindrome("abb")<<std::endl;
    return 0;
}
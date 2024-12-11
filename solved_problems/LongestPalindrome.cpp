#include "minclude.h"

class Solution 
{
public:

    int longestPalindrome(string s) 
    {
        int longest_odd = 0;
        int sum = 0;
        
        unordered_map<char, int> counts;

        for(auto& c : s)
        {
            counts[c]++;
        }        

        for(const auto& [key, value] : counts)
        {
            cout<<"key: "<<key<<" value: "<<value<<"\n";
            if(value & 1)
            {
                if(value > longest_odd)
                {
                    cout<<"A\n";
                    if(value)
                    {
                        sum--;
                    }

                    longest_odd = value;
                    sum += longest_odd;
                }
                else
                {
                    cout<<"B\n";
                    sum += value - 1;
                }
            }
            else
            {
                cout<<"C\n";
                sum += value;
            }
        }

        return sum;
    }
};

int main()
{
    Solution sol{};
    sol.longestPalindrome("a");
}
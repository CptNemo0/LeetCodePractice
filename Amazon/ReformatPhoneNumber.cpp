#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Solution 
{
public:
    string reformatNumber(string number) 
    {
        const auto is_num = [](char c)
        {
            return (c >= '0' && c <= '9');
        };

        stringstream ss;

        for(const auto& n : number)
        {
            if(!is_num(n)) continue;
            ss << n;
        }

        number = ss.str();
        ss = stringstream(string());

        int ctr = 0;
        int top = 3;
        for(int i = 0 ; i < number.length() ; i++)
        {
            if(ctr == top)
            {
                ss << '-';
                ctr = 0;
            }

            if(!ctr && number.length() - i == 4)
            {
                top = 2;
            }

            ss << number[i];
            ctr++;
        }

        return ss.str();
    }
};
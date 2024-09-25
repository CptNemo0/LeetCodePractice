#include <pplwin.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

string rle(string s)
{
    int counter = 0;
    char current = -1;
    stringstream ss;
    for(int i = 0 ; i < s.length() ; i++)
    {
        current = s[i];
        counter = 1;

        if(i + 1 == s.length())
        {
            ss << counter;
            ss << current;
        }

        for(int j = i + 1 ; j < s.length() ; j++)
        {
            if(current == s[j])
            {
                counter++;
            }
            else
            {
                ss << counter;
                ss << current;
                i = j - 1;
                break;
            }
            if(j + 1 == s.length())
            {
                ss << counter;
                ss << current;
                i = j;
            }
        }
    }

    return ss.str();
}

string countAndSay(int n)
{
    if(n == 1)
    {
        return "1";
    }
    else
    {
        string result = countAndSay(n - 1);
        result = rle(result);

        return result;
    }
}

int main()
{
    cout<<countAndSay(10)<<"\n";
    return 0;
}

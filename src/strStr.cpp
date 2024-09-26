#include <string>
#include <iostream>

using namespace std;

int strStr(string haystack, string needle)
{
    int return_value = -1;

    for(int i = 0 ; i < haystack.length() ; i++)
    {
        if(haystack[i] == needle[0])
        {   
            int c = 1;

            if(c == needle.length())
            {
                return i;
            }


            for(int j = 1; j < needle.length(); j++)
            {
                if(i + j == haystack.length())
                {
                    return -1;
                }

                if(haystack[i + j] == needle[j])
                {
                    c++;

                    if(c == needle.length())
                    {
                        return i;
                    }
                }                
            }
        }
    }

    return return_value;
}

int main()
{
    string haystack = "a", needle = "a";

    cout<<strStr(haystack, needle);
}
#include <string>
#include <iostream>

using namespace std;

bool canPermutatePalindrome(string s)
{
    int characters [26];

    for(int i = 0 ; i < 26 ; i++)
    {
        characters[i] = 0;
    }

    for(const char c : s)
    {
        characters[(int)c - 97]++;
    }

    bool odd = s.length() & 1;

    for(int i = 0 ; i < 26 ; i++)
    {
        if(characters[i] & 1)
        {
            if(!odd)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    cout<<canPermutatePalindrome("aaaassssc")<<endl;
}

#include<string>
#include<map>
#include<iostream>
#include<windows.h>
using namespace std;

int firstUniqChar(string s) 
{
    
    int frequencies[26];
    ZeroMemory(frequencies, 26 * sizeof(int));

    for(auto& c : s)
    {
        frequencies[c - 'a']++;
    }

    for(int i = 0 ; i < s.length() ; i++)
    {
        if(frequencies[s[i] - 'a'] == 1)
        {
            return i; 
        }
    }

    return -1;
}


int main()
{
    std::cout<<firstUniqChar("qfqwqweefb")<<"\n";
    return 0;
}   
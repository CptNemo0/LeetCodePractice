#include<unordered_map>
#include<string>
#include<iostream>

using namespace std;

bool isAnagram(string s, string t) 
{
    if(s.size() != t.size()) return false;

    unordered_map<char, int> chars;

    for(int i = 0 ; i < s.size() ; i++)
    {
        chars[s[i]]++;
        chars[t[i]]--;
    }
    
    for(const auto& [k, v] : chars)
    {
        //std::cout<<"k: "<<k<<" v: "<<v<<std::endl;
        if(v != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    isAnagram(
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbba"
    );
    return 0;
}
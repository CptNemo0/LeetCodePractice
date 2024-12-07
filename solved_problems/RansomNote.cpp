#include "minclude.h"

class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char, int> map;

        for(auto& a : magazine)
        {
            map[a]++;
        }

        for(auto& a : ransomNote)
        {
            map[a]--;
        }

        for(const auto& [key, value] : map)
        {
            if(value < 0) return false;
        }

        return true;
    }
};
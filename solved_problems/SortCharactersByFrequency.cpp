#include "minclude.h"

class Solution 
{
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> frequencies;

        for(auto& c : s)
        {
            frequencies[c]++;
        }

        auto sorting_lambda = [&frequencies](char a, char b)
        {
            if(frequencies[a] == frequencies[b]) return a > b;
            return frequencies[a] > frequencies[b];
        };  

        sort(s.begin(), s.end(), sorting_lambda);
        return s;
    }
};
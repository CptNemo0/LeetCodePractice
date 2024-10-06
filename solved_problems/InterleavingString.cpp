#include <string>
#include <iostream>
#include <sstream>
using namespace std;

bool recursive_part (const string& s1, const string& s2, const string& s3, int idx1, int idx2, bool cache[101][101])
{
    int idx3 = idx1 + idx2;

    if(idx3 == s3.length())
    {
        return true;
    }
    
    if(cache[idx1][idx2])
    {
        return false;
    }

    bool s1ok = s1[idx1] == s3[idx3] && idx1 < s1.length();
    bool s2ok = s2[idx2] == s3[idx3] && idx2 < s2.length();

    if(s1ok && s2ok)
    {
        bool result1 = recursive_part(s1, s2, s3, idx1 + 1, idx2, cache);
        bool result2 = recursive_part(s1, s2, s3, idx1, idx2 + 1, cache);

        return result1 + result2;
    }

    if(s1ok)
    {
        return recursive_part(s1, s2, s3, idx1 + 1, idx2, cache);
    }
    if(s2ok)
    {
        return recursive_part(s1, s2, s3, idx1, idx2 + 1, cache);
    }

    cache[idx1][idx2] = true;
    return false;
}

bool isInterleave(string s1, string s2, string s3) 
{
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();

    if(len1 + len2 != len3)
    {
        return false;
    }

    bool cache [101][101];
    std::fill(&cache[0][0], &cache[100][100], false);

    //return recursive_part(s1, s2, s3, 0, 0, cache);

    cache[len1][len2] = true;

    for(int idx1 = len1 ; idx1 > -1 ; idx1--)
    {
        for(int idx2 = len2 ; idx2 > -1 ; idx2--)
        {
            int idx3 = idx1 + idx2;

            if(idx1 < s1.length() && s1[idx1] == s3[idx3] && cache[idx1 + 1][idx2])
            {
                cache[idx1][idx2] = true;
            }

            if(idx2 < s2.length() && s2[idx2] == s3[idx3] && cache[idx1][idx2 + 1])
            {
                cache[idx1][idx2] = true;
            }
        }
    }

    return cache[0][0];

}

int main()
{
    cout<<isInterleave("abbbbbbcabbacaacccababaabcccabcacbcaabbbacccaaaaaababbbacbb", "ccaacabbacaccacababbbbabbcacccacccccaabaababacbbacabbbbabc", "cacbabbacbbbabcbaacbbaccacaacaacccabababbbababcccbabcabbaccabcccacccaabbcbcaccccaaaaabaaaaababbbbacbbabacbbacabbbbabc");
    return 0;
}
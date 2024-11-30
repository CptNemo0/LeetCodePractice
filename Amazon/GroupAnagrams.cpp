#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> groups;

        for(auto& str : strs)
        {
            auto tmp = str;
            sort(tmp.begin(), tmp.end());
            groups[tmp].push_back(str);
        }

        vector<vector<string>> return_value;
        for(const auto& [s, v] : groups)
        {
            return_value.push_back(v);
        }
        return return_value;
    }
};

int main()
{
    vector<string> z {"eat","tea","tan","ate","nat","bat"};
    Solution sol {};
    auto rv = sol.groupAnagrams(z);
    for(auto& v : rv)
    {
        for(auto& e : v)
        {
            std::cout<<e<<" ";
        }
        std::cout<<"\n";
    }
}
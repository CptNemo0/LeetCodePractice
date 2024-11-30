#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution 
{
public:

    const unordered_map<int, vector<char>> map
    {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };

    void dfs(string current, int depth, const string& digits, vector<string>& return_value)
    {
        
        char c = digits[depth];

   
        
        if(current.length() + 1 == digits.length())
        {
            for(auto z : map.at(c))
            {
                return_value.push_back(current + z);
            }
        }
        else
        {
            for(auto z : map.at(c))
            {
                dfs(current + z, depth + 1, digits, return_value);
            }
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        if (digits == "") return {};
        vector<string> return_value;
        dfs("", 0, digits, return_value);
        return return_value;
    }
};

int main()
{
    return 0;
}
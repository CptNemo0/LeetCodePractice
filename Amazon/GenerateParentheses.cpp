#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution 
{
public:
    void dfs(string current, int opened, int closed, int pairs, vector<string>& return_value)
    {
        //std::cout<<current<<std::endl;
        if(opened == pairs && closed == pairs)
        {
            //std::cout<<"pushing current: "<<current<<std::endl;
            return_value.push_back(current);
            return;
        }

        if(current[opened + closed - 1] == '(')
        {
            if(opened < pairs)
            {
                dfs(current + "(", opened + 1, closed, pairs, return_value);
            }
            dfs(current + ")", opened, closed + 1, pairs, return_value);
        }
        else
        {
            if(opened < pairs)
            {
                dfs(current + "(", opened + 1, closed, pairs, return_value);
            }
            
            if(opened > closed)
            {
                dfs(current + ")", opened, closed + 1, pairs, return_value);
            }
        }
    }

    vector<string> generateParenthesis(int n) 
    {
        vector<string> return_value;
        dfs("(", 1, 0, n, return_value);
        return return_value;
    }
};

int main()
{
    Solution s = Solution();
    auto v = s.generateParenthesis(3);
    for(auto& e : v)
    {
        std::cout<<e<<std::endl;
    }
}
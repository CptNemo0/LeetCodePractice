#include<vector>
#include<unordered_set>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n = s.length();
        vector<bool> dp (n + 1, false);
        dp[n] = true;

        for(int i = n - 1; i > -1 ; i--)
        {
            for(auto& word : wordDict)
            {
                int m = word.length();
                if(m + i > n) continue;
                if(word != s.substr(i, m)) continue;
                dp[i] = dp[i + m];
                if (dp[i]) break;
            }
        }
        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n = s.length();
        
        queue<int> q;
        unordered_map<int, bool> map;
        map.emplace(n, true);
        q.push(0);

        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            if(top == n) return true;
            
            if(!map.contains(top))
            {
                map[top] = false;
            }
            else
            {
                if(!map[top]) continue;    
            }

            
            for(auto& word : wordDict)
            {
                int m = word.length();
                if(top + m > n) continue;
                if(word != s.substr(top, m)) continue;
                q.push(top + m);
                map[top] = true;
            }
        }

        return false;
    }
};
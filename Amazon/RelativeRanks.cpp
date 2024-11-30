#include<vector>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution 
{
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        unordered_map<int, int> map;
        priority_queue<int, vector<int>, less_equal<int>> q;
        vector<string> return_value (score.size(), "");
        
        for(int i = 0 ; i < score.size() ; i++)
        {
            map.emplace(score[i], i);
            q.push(score[i]);
        }

        int ctr = 0;

        while(!q.empty())
        {
            int s = q.top();
            q.pop();
            int idx = map[s];

            switch (ctr)
            {
            case 0:
                return_value[idx] = "Gold Medal";
                break;
            case 1:
                return_value[idx] = "Silver Medal";
                break;
            case 2:
                return_value[idx] = "Bronze Medal";
                break;
            default:
                return_value[idx] = to_string(ctr + 1);
                break;
            }
            ctr++;
        }

        return return_value;
    }
};
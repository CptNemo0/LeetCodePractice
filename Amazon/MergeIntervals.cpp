#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= end)
            {
                end = max(end,intervals[i][1]);
            }
            else
            {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};

int main()
{
    vector<vector<int>> intervals
    { {2, 3}, {5, 7}, {0, 1}, {4, 6}, {5, 5}, {4, 6}, {5, 6}, {1, 3}, {4, 4}, {0, 0}, {3, 5}, {2, 2},  } ;
    Solution sol {};
    sol.merge(intervals);
    return 0;
}
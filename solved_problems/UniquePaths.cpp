#include "minclude.h"

class Solution {
public:
    int uniquePathsBFS(int m, int n) 
    {
        vector<vector<int>> values (m, vector<int>(n, 0));
        vector<vector<bool>> inserted (m, vector<bool>(n, false));
        
        values[m - 1][n - 1] = 1;

        auto in_bounds = [&m, &n](int x, int y)
        {
            return (x > -1 && x < n && y > -1 && y < m);
        };

        queue<pair<int, int>> q;
        q.push({n - 1, m - 1});

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            
            if(in_bounds(x - 1, y))
            {
                values[y][x - 1] += values[y][x];
                if(!inserted[y][x - 1])
                {
                    q.push({x - 1, y});
                    inserted[y][x] = true;
                }
                
            }

            if(in_bounds(x, y - 1))
            {
                values[y - 1][x] += values[y][x];
                if(!inserted[y - 1][x])
                {
                    q.push({x, y - 1});
                    inserted[y - 1][x] = true;
                }
            }
        }
        return values[0][0];
    }

    int uniquePathsDP(int m, int n)
    {
        vector<vector<int>> values (m, vector<int>(n, 1));

        for(int y = m - 2 ; y > -1 ; y--)
        {
            for(int x = n - 2 ; x > -1 ; x--)
            {
                values[y][x] = values[y + 1][x] + values[y][x + 1];
            }
        }

        return values[0][0];
    }   
};

int main()
{
    Solution sol {};
    sol.uniquePaths(3, 7);
}
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

class Solution 
{
public:
    vector<pair<int, int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int orangesRotting(vector<vector<int>>& grid) 
    {
        int healthy_oranges = 0;
        int rotten_oranges  = 0;       
        queue<pair<int, int>> q;

        int time = 0;
        int q_size = 0;

        int m = grid.size();
        int n = grid[0].size();

        for(int y = 0 ; y < m ; y++)
        {
            for(int x = 0 ; x < n ; x++)
            {
                if(grid[y][x] == 1)
                {
                    healthy_oranges++;
                }
                else if(grid[y][x] == 2)
                {
                    rotten_oranges++;
                    q.emplace(x, y);
                }
            }
        }
        
        if(!healthy_oranges) return 0;

        while(!q.empty())
        {
            q_size = q.size();
            
            for(int _ = 0 ; _ < q_size ; _++)
            {
                auto current = q.front();
                q.pop();
                
                for(auto& direction : directions)
                {
                    int xx = current.first + direction.first;  
                    int yy = current.second + direction.second;  

                    if(!((xx >= 0 && xx < n) && (yy >= 0 && yy < m))) continue;
                    
                    if(grid[yy][xx] == 1)
                    {
                        rotten_oranges++;
                        grid[yy][xx] = 2;
                        q.emplace(xx, yy);
                    }
                }
            }

            time++;
        }

        if(healthy_oranges != rotten_oranges) return -1;

        return time - 1;
    }
};

int main()
{
    //vector<vector<int>> v {{2,1,1},{0,1,1},{1,0,1}};
    vector<vector<int>> v {{0, 2}};
    Solution s {};

    s.orangesRotting(v);
}
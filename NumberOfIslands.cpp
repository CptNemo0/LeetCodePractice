#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int numIslands(vector<vector<char>>& grid) 
{
    int m = static_cast<int>(grid.size());
    int n = static_cast<int>(grid[0].size());
    vector<pair<int,int>> directions  {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool visited[300][300];

    int return_value = 0;

    for(int i = 0 ; i < 300 ; i++)
    {
        for(int j = 0 ; j < 300 ; j++)
        {
            visited[i][j] = false;
        }
    }

    auto bfs = [&visited, &grid, directions, m, n](int i, int j)
    {
        queue<pair<int, int>> q;
        visited[i][j] = true;
        q.emplace(i, j);

        while(!q.empty())
        {
            const auto [ii, jj] = q.front();
            q.pop();

            for(const auto[di, dj] : directions)
            {
                int new_i = ii + di;
                int new_j = jj + dj;

                if(new_i < 0 || new_i >= m)
                {
                    continue;
                }

                if(new_j < 0 || new_i >= n)
                {
                    continue;
                }

                if (grid[new_i][new_j] == '1' && !visited[new_i][new_j])
                {
                    q.emplace(new_i, new_j);
                    visited[new_i][new_j] = true;
                }
            }
        }
    };

    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(grid[i][j] == '1' && !visited[i][j])
            {
                bfs(i, j);
                return_value++;
            }
        }
    }

    return return_value;
}

int main()
{

}
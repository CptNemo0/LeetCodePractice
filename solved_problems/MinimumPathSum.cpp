#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

int minPathSum(vector<vector<int>>& grid) 
{
    int return_value =  INT_MAX; //grid[0][0];
    
    int m = grid.size();
    int n = grid[0].size();
     
    std::pair<int, int> previous[201][201];
    int g_score[201][201];
    int f_score[201][201];
 
    for(int i = 0 ; i < 201 ; i++)
    {
        for(int j = 0 ; j < 201 ; j++)
        {
            g_score[i][j] = 99999999;
            f_score[j][i] = 99999999;
            previous[i][j].first = -1;
            previous[i][j].second = -2;
        }
    }

    auto comapre_lambda = [f_score](std::pair<int, int> a, std::pair<int, int> b)
    {
        return (f_score[a.second][ a.first] > f_score[b.second][b.first]);
    };

    vector<std::pair<int, int>> queue;

    auto heuristic = [n, m](int x, int y)
    {
        return (n - x) * ( n - x) + (m - y) * ( m - y);
    };
  
    auto insertion_sort = [f_score, &queue]()
    {
        for (int i = 1; i < queue.size(); ++i) 
        {
            pair<int, int> key = queue[i];
            int j = i - 1;

            auto pp = queue[j];

            while (j >= 0 && f_score[pp.second][ pp.first] > f_score[key.second][ key.first]) 
            {
                queue[j + 1] = queue[j];
                j = j - 1;
            }
            queue[j + 1] = key;
        }
    };

    previous[0][0] = std::make_pair(-1, -1);
    g_score[0][0] = grid[0][0];
    f_score[0][0] = grid[0][0] + heuristic(0, 0);
    
    queue.emplace_back(0, 0);

    while(queue.size() > 0)
    {
        auto current = queue[0];
        queue.erase(queue.begin());

        if ((current.first == n - 1) && (current.second == m - 1))
        {
            if(return_value > g_score[current.second][current.first])
            {
                return_value = g_score[current.second][current.first];
            }
        }

        if(current.first < n - 1)
        {   
            pair<int, int> right = make_pair(current.first + 1, current.second);
            
            int predicted_score = g_score[current.second][current.first] + grid[right.second][right.first];
            if( predicted_score < g_score[right.second][right.first])
            {
                previous[right.second][right.first] = current;
                g_score[right.second][right.first] = predicted_score;
                f_score[right.second][right.first] = predicted_score + heuristic(right.first, right.second);

                if(auto result = std::find(queue.begin(), queue.end(), right) ; result == queue.end())
                {
                    queue.push_back(right);
                    insertion_sort();
                }
                else
                {
                    insertion_sort();
                }
            }    
        }

        if(current.second < m - 1)
        {
            pair<int, int> down = make_pair(current.first, current.second + 1);
            
            int predicted_score = g_score[current.second][current.first] + grid[down.second][down.first];
            
            if( predicted_score < g_score[down.second][down.first])
            {
                previous[down.second][down.first] = current;
                g_score[down.second][down.first] = predicted_score;
                f_score[down.second][down.first] = predicted_score + heuristic(down.first, down.first);

                if(auto result = std::find(queue.begin(), queue.end(), down) ; result == queue.end())
                {
                    queue.push_back(down);
                    insertion_sort();
                }
                else
                {
                    insertion_sort();
                }
            }
        }
    }

    return return_value;
}

int main()
{
    
    vector<vector<int>> grid  {{1,3,1},{1,5,1},{4,2,1}};
    
    cout<<minPathSum(grid);

    return 0;
}

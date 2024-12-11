#include "minclude.h"

class Solution 
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        const vector<pair<int, int>> directions 
        {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };

        int rows = image.size();
        int cols = image[0].size();
        
        vector<vector<bool>> visited (rows, vector<bool>(cols, false));

        auto in_bounds = [cols, rows](int x, int y)
        {
            return (x > -1 && x < cols && y > -1 && y < rows);
        };

        int begining_color = image[sr][sc];

        queue<pair<int, int>> q;
        q.push({sc, sr});

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            image[y][x] = color;

            for(const auto& [dx, dy] : directions)
            {
                if(!in_bounds(x + dx, y + dy)) continue;
                if(image[y + dy][x + dx] != begining_color) continue;
                if(visited[y + dy][x + dx]) continue;
                q.push({x + dx, y + dy});
                visited[y + dy][x + dx] = true;
            }
        }

        return image;
    }
};

int main()
{
    vector<vector<int>> a {{1,1,1},{1,1,0},{1,0,1}};
    Solution sol {};
    sol.floodFill(a, 1, 1, 2);
    return 0;
}
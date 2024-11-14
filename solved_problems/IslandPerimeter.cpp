#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int islandPerimeter(vector<vector<int>>& grid) 
{
    int edges = 0;

    int height = grid.size();
    int width = grid[0].size();

    vector<int> visited (height * width, 0);

    for(int i = 0 ; i < height ; i++)
    {
        for(int j = 0; j < width ; j++)
        {   
            if(grid[i][j] && !visited[i * width + j])
            {
                queue<pair<int, int>> q;
                edges += 4;
                q.emplace(i, j);
                visited[i * width + j] = 1;

                while(!q.empty())
                {
                    const auto [y, x] = q.front();

                    std::cout<<"We are at y: "<<y<<", x: "<<x<<std::endl;

                    q.pop();
                    if(x + 1 < width)
                    {
                        if(grid[y][x + 1])
                        {
                            std::cout<<"Found something to the right, ";
                            
                            if(!visited[y * width + x + 1])
                            {
                                
                                edges += 2;
                                visited[y * width + x + 1] = 1;
                                q.emplace(y, x + 1);
                                std::cout<<"it is a new land, edges += 2: " << edges <<"\n";
                            }
                            else
                            {
                                
                                edges -= 2;
                                std::cout<<"we've been here before, edges -= 2: " << edges <<"\n";
                            }
                        }
                    }

                    if(y + 1 < height)
                    {
                        if(grid[y + 1][x])
                        {
                            std::cout<<"Found something down, ";
                            
                            if(!visited[(y + 1) * width + x])
                            {
                                
                                edges += 2;
                                visited[(y + 1) * width + x] = 1;
                                q.emplace(y + 1, x);
                                std::cout<<"it is a new land, edges += 2: " << edges <<"\n";
                            }
                            else
                            {
                                
                                edges -= 2;
                                std::cout<<"we've been here before, edges -= 2: " << edges <<"\n";
                            }
                        }
                    }
                }
            }
        }
    }

    return edges;
}

int main()
{
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0}, {0,1,0,0}, {1,1,0,0}};
    std::cout<<islandPerimeter(grid)<<std::endl;
    return 0;
}
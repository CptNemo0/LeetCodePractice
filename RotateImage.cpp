#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct vec2
{
    float x;
    float y;

    vec2(float x_, float y_) : x(x_), y(y_) {}

    vec2 operator-(vec2& a)
    {
        return vec2(x - a.x, y - a.y);
    }

    vec2 operator+(vec2& a)
    {
        return vec2(x + a.x, y + a.y);
    }

    bool operator==(vec2& a)
    {
        return ((a.x == x) && (a.y == y));
    }

    string Log()
    {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }
};

vec2 get_center(int n)
{
    if(n & 1)
    {
        int c = floorf(n /2);
        return vec2(c, c);
    }
    else
    {
        float c = (n / 2) - 0.5f;
        return vec2(c, c);
    }
}

vec2 get_new_cell(vec2& cell,  vec2& center, const int n)
{
    vec2 displacement = cell - center;
    vec2 perpendicular (displacement.y, -displacement.x);
    auto r = center + perpendicular;
    return center + perpendicular;
}

void rotate(vector<vector<int>>& matrix)
{
    int n = static_cast<int>(matrix.size());

    if(n == 1)
    {
        return;
    }

    vec2 center = get_center(n);

    int tmp = 0;

    int x_start = -1;
    vec2 starting_cell (-122112121.0f, -12121212.0f);
    int ctr = 0;

    int y_ceil = n & 1 ? ceilf(n / 2) : n / 2;

    cout<<"y_ceil: "<<y_ceil<<endl;

    for(int y = 0 ; y <= y_ceil ; y++)
    {
        x_start++;
        cout<<"x_start: "<<x_start<<endl;

        int x_ceil = n - 1 - (y + 1);
        cout<<"x_ceil: "<<x_ceil<<endl;

        for(int x = x_start ; x <= x_ceil ; x++)
        {
            starting_cell = vec2 (x, n - (y + 1));
            
            vec2 cell  (x, n - (y + 1));
            vec2 new_cell = get_new_cell(cell, center, n);
            int new_cell_x_idx = new_cell.x;
            int new_cell_y_idx = (n - 1) - new_cell.y ;

            cout<<"swapping: "<< matrix[y][x] << " with " <<matrix[new_cell_y_idx][new_cell_x_idx] << "\n";

            tmp = matrix[new_cell_y_idx][new_cell_x_idx];
            matrix[new_cell_y_idx][new_cell_x_idx] = matrix[y][x];

            cell = new_cell;

            while (!(starting_cell == cell))
            {
                new_cell = get_new_cell(cell, center, n);
                new_cell_x_idx = new_cell.x;
                new_cell_y_idx = (n - 1) - new_cell.y;

                cout<<"swapping: "<< tmp << " with " <<matrix[new_cell_y_idx][new_cell_x_idx] << "\n";

                int tmp2 = matrix[new_cell_y_idx][new_cell_x_idx];
                matrix[new_cell_y_idx][new_cell_x_idx] = tmp;
                tmp = tmp2;
                
                cell = new_cell;
            }
            
        } 
    }

}

int main()
{
    cout<<"GO!\n";
    vector<vector<int>> a {{5,1,9,11},{2,4,8,10},{13,3,6,7}, {15,14,12,16}};
    rotate(a);
    return 0;
}
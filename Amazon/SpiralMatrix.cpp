#include<vector>
#include<iostream>

using namespace std;

class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int right = n;
        int down  = m - 1;
        int left  = n - 1;
        int up    = m - 2;

        int rc = right;
        int dc = down;
        int lc = left;
        int uc = up;

        int x = 0;
        int y = 0;

        vector<int> return_value;
        return_value.push_back(matrix[y][x]);
        rc--;

        while(true)
        {
            if(return_value.size() == m * n) break;
            
            if(rc)
            {
                x++;
                rc--;
                return_value.push_back(matrix[y][x]);
            }
            else if(dc)
            {
                y++;
                dc--;
                return_value.push_back(matrix[y][x]);
            }
            else if(lc)
            {
                x--;
                lc--;
                return_value.push_back(matrix[y][x]);
            }
            else if(uc)
            {
                y--;
                uc--;
                return_value.push_back(matrix[y][x]);
            }
            else
            {
                right -= 2; 
                down  -= 2; 
                left  -= 2; 
                up    -= 2;

                rc = right;
                dc = down;
                lc = left;
                uc = up; 
            }
        }
    
        return return_value;
    }
};

int main()
{
    vector<vector<int>> v {{1,2,3,4,5,6,7,8,9,10},{11,12,13,14,15,16,17,18,19,20},{21,22,23,24,25,26,27,28,29,30},{31,32,33,34,35,36,37,38,39,40},{41,42,43,44,45,46,47,48,49,50},{51,52,53,54,55,56,57,58,59,60},{61,62,63,64,65,66,67,68,69,70},{71,72,73,74,75,76,77,78,79,80},{81,82,83,84,85,86,87,88,89,90},{91,92,93,94,95,96,97,98,99,100}};

    Solution s {};

    s.spiralOrder(v);
}
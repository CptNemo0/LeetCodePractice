#include<vector>
#include<iostream>

using namespace std;

class Solution 
{
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> return_value;

        for(int i = 0 ; i < m ; i++)
        {
            int minimum_row = INT32_MAX;
            int minimum_idx = -1;
            
            for(int j = 0; j < n ; j++)
            {
                if(matrix[i][j] < minimum_row)
                {
                    minimum_row = matrix[i][j];
                    minimum_idx = j;
                }
            }

            cout<<"minimum_row: "<<minimum_row<<", minimum_idx: "<<minimum_idx<<endl;

            int maximum_col = INT32_MIN;
            int maximum_idx = -1;

            for(int j = 0; j < m ; j++)
            {
                if(matrix[j][minimum_idx] > maximum_col)
                {
                    maximum_col = matrix[j][minimum_idx];
                    maximum_idx = j;
                }
            }

            cout<<"maximum_col: "<<maximum_col<<", maximum_idx: "<<maximum_idx<<endl;

            if(minimum_row == maximum_col) return_value.push_back(maximum_col);
        }

        return return_value;
    }
};

int main()
{
    vector<vector<int>> a {{1,10,4,2},{9,3,8,7},{15,16,17,12}};
    Solution s {};
    s.luckyNumbers(a);
}
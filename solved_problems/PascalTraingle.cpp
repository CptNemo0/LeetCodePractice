#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> return_value;
    return_value.push_back({1});

    while(return_value.size() < numRows)
    {
        vector<int> row;

        for(int i = 0 ; i < return_value.back().size() ; i++)
        {
            if(i == 0)
            {
                row.push_back(1);
                continue;
            }

            row.push_back(return_value.back()[i] + return_value.back()[i - 1]);
        }
        row.push_back(1);
        return_value.push_back(row);
    }

    return return_value;
}

int main()
{
    return 0;
}

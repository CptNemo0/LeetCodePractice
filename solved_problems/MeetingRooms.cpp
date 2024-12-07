#include "minclude.h"

struct ListNode
{
    ListNode* next;
    int val;
};


bool solution(vector<vector<int>>& input)
{
    auto sorting_lambda = [](vector<int>& a, vector<int>& b)
    {
        return a[0] > b[0];
    };

    sort(input.begin(), input.end(), sorting_lambda);

    for(int i = 0 ; i < input.size() - 1; i++)
    {
        if(input[i][1] > input[i + 1][0]) return false;
    }

    return true;
}

int main()
{
    return 0;
}
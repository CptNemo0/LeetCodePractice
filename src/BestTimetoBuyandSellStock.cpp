#include <vector>
#include <stack>
#include <iostream>

using namespace std;

inline int branchless_max(int a, int b)
{
    constexpr int sign_bit = 31;
    const int difference = a - b;
    const int b_greater = (difference >> sign_bit) & 1;
    return a - difference * b_greater;
}

inline int branchless_min(int a, int b)
{
    constexpr int sign_bit = 31;
    const int difference = a - b;
    const int b_greater = (difference >> sign_bit) & 1;
    return b - (b - a) * b_greater;
}

int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    if (n == 0)
    {
        return 0;
    }
    int buy = prices[0];
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        int cost = prices[i] - buy;
        profit = branchless_max(profit, cost);
        buy = min(buy, prices[i]);
    }
    return profit;
}

int main()
{
    vector<int> v {7,1,5,3,6,4};
    cout<<maxProfit(v);
}

#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) 
{
    if (prices.size() < 2) return 0;

    int return_value = 0;
    auto left = prices.begin();
    auto right = next(left);

    while(right != prices.end())
    {
        int difference = *right - *left;

        if(difference < 0)
        {
            left = right;
            right = next(right);
        }
        else
        {
            if(difference > return_value)
            {
                return_value = difference;
            }
            right = next(right);
        }
    }

    return return_value;
}

int main()
{
    return 0;
}
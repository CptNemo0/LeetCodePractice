#include "minclude.h"

class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if (amount < 1) return -1;
        priority_queue<int, vector<int>, less<int>> q;
        for(auto& c : coins)
        {
            q.push(c);
        }

        int ctr = 0;

        while(!q.empty())
        {  
            cout<<"q.top(): "<<q.top()<<" value: "<<amount<<"ctr: "<<ctr<<endl;
            if(q.top() == amount)
            {
                amount = 0;
                ctr++;
                break;
            }
            else if(q.top() < amount)
            {
                ctr++;
                amount -= q.top();
            }
            else
            {
                q.pop();
            }
        }

        return amount == 0 ? ctr : -1;
    }
};

int main()
{
    Solution sol {};
    vector<int> coins {1,2,5};
    sol.coinChange(coins, 11);
    return 0;
}
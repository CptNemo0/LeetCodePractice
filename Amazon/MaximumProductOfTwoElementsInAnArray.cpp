#include<vector>
#include<queue>

using namespace std;

class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        priority_queue<int, vector<int>, less_equal<int>> q;
        for(auto& n : nums)        
        {
            q.push(n);
        }
        int a = q.top();
        q.pop();
        return (a - 1) * (q.top() - 1);
    }
};

int main()
{

}
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        std::priority_queue<int, vector<int>, less_equal<int>> q;

        for(auto& n : nums)
        {
            q.push(n);
        }

        for(int i = 0 ; i < k - 1 ; i++)
        {
            q.pop();
        }

        return q.top();
    }
};

int main()
{

}
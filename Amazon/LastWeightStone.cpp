#include<vector>
#include<queue>

using namespace std;

class Solution 
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int, vector<int>, less_equal<int>> max_heap;

        for(auto& stone : stones)
        {
            max_heap.push(stone);
        }

        while(max_heap.size() > 1)
        {
            int x = max_heap.top();
            max_heap.pop();
            int y = max_heap.top();
            max_heap.pop();

            if(x != y)
            {
                max_heap.push(abs(y - x));
            }
        }

        if(max_heap.size()) return max_heap.top();
        return 0;
    }
};

int main()
{
    return 0;
}
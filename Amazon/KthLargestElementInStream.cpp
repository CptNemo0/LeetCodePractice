#include<vector>
#include<queue>

using namespace std;

    class KthLargest {
    public:
        priority_queue<int, vector<int>, greater<int>>    min_heap_;
        int k_;

        KthLargest(int k, vector<int>& nums) 
        {
            k_ = k;
            for(auto& n : nums)
            {
                add(n);
            }
        }
        
        int add(int val) 
        {
            if(val <= min_heap_.top()) return;

            min_heap_.push(val);
            
            while(min_heap_.size() > k_)
            {
                min_heap_.pop();
            }
            return min_heap_.top();
        }
    };

int main()
{

}
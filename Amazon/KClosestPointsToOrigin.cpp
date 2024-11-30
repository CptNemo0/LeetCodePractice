#include<vector>
#include<iostream>
#include<queue>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        typedef tuple<int, int, int> record;
        
        auto cmp = [](record& a, record& b)
        {
            const auto [x1, x2, x3] = a;
            const auto [y1, y2, y3] = b;
            return x3 > y3;
        };

        priority_queue<record, vector<record>, decltype(cmp)> records;

        for(auto& point : points)
        {
            int mag = point[0] * point[0] + point[1] * point[1];
            records.emplace(point[0], point[1], mag);
        }

    
        vector<vector<int>> return_value;
        for(int i = 0 ; i < k ; i++)
        {
            const auto [x, y, m] = records.top();
            records.pop();
            
            return_value.push_back({x, y});
        }
        return return_value;
    }
};

int main()
{
    Solution s = Solution();
    vector<vector<int>> z
    {
        {3, 3},
        {5, -1},
        {-2, 4}
    };
    
    z = s.kClosest(z, 2);

    for(auto x : z)
    {
        std::cout<<x[0]<<" "<<x[1]<<std::endl;
    }
    return 0;
}
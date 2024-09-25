#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) 
{
    int n = static_cast<int>(height.size());
    int return_value = 0;

    for(int i = 0 ; i < n ; i++)
    {
        auto max_left = 0;
        auto max_right = 0;
        if(i != 0)
        {
            max_left = (*max_element(height.begin(), height.begin() + i));
        }

        if(i != n - 1)
        {
            max_right = (*max_element(height.begin() + i + 1, height.end()));
        }

        return_value += min(max_left, max_left) - height[i];
    }

    return return_value;
}

int main()
{
    cout<<"go\n";
    vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height)<<endl;
    return 0;
}
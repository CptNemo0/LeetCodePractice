#include<vector>
#include<math.h>
#include<xutility>

using namespace std;

class Solution 
{
public:

    long long func(vector<int> &chiles , int hourly)
    {
        int n = chiles.size();
        long long totalHours = 0;
        for(int i = 0 ; i < n ; i++)
        {
            totalHours += ceil((double)chiles[i] / (double)hourly);
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while(left <= right)
        {
            int mid = (left + right)/2;
            long long totalHrs = func(piles ,mid);
            if(totalHrs <= h)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        
        return left; 
    }
};

int main()
{

}
#include<iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
        {
            return 1.0;
        }

        if(x == 1.0f || x == -1.0f)
        {
            return 1.0;
        }

        bool should_invert = false;
        double result = 1.0;

        if(n < 0)
        {
            x = 1.0 / x;
            should_invert = true;
        }

        if(should_invert)
        {
            bool a = (n & 1);

            auto nb = n / 2;
            
            double sq = x * x;
            for(int i = 0 ; i > nb; i--)
            {
                result *= sq;
            }

            if(a)
            {
                result *= x;
            }
        }
        else
        {
            auto nb = n / 2;
            bool a = (n & 1);
            double sq = x * x;
            for(int i = 0 ; i < nb; i++)
            {
                result *= sq;
            }

            if(a)
            {
                result *= x;
            }
        }
        std::cout<<result<<std::endl;
        return result;
    }
};

int main()
{
    auto s = Solution();
    s.myPow(2.0, -2);
    return 0;
}
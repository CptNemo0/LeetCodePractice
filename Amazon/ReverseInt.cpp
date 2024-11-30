#include<stack>
#include<iostream>

using namespace std;

class Solution 
{
public:
    int reverse(int x) 
    {
        if(x > -10 && x < 10) return x;
        int sign = x > -1 ? 1 : -1;
        int x = abs(x);

        int reversed = 0;

        int multiplier = 1;

        stack<int> s;

        while (x >= 1)
        {
            int digit = x % 10;
            s.push(digit);
            x /= 10;
        }

        while(!s.empty())
        {
            int current = s.top();;
            s.pop();
            if(s.empty())
            {
                s.push(current);
                break;
            }
            reversed += multiplier * current;
            multiplier *= 10;
        }

        if(multiplier == 1000'000'000)
        {
            if(sign > 0)
            {
                int barrier = 2147483647;
                int diff = barrier - reversed;
                int max_number = diff / 1'000'000'000;
        
                if(max_number < s.top())
                {
                    return 0;
                }
            }
            else
            {
                int barrier = 2147483647;
                int diff = barrier - reversed;
                diff++;
                int max_number = diff / 1000000000;

                if(max_number < s.top())
                {
                    return 0;
                }
            }
        }

        return (reversed + multiplier * s.top()) * sign;
    }
};

int main()
{
    int reversed = reverse(-123);
    cout<<reversed<<endl;
}
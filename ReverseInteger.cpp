#include <iostream>
#include <stack>

using  namespace std;

int reverse(int x)
{
    int sign = x > -1 ? 1 : -1;
    int x_copy = abs(x);

    if(x_copy < 10)
    {
        return x_copy * sign;
    }

    int reversed = 0;

    int multiplier = 1;

    stack<int> s;

    while (x_copy >= 1)
    {
        int digit = x_copy % 10;
        s.push(digit);
        x_copy /= 10;
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

    if(multiplier == 1000000000)
    {
        if(sign > 0)
        {
            int barrier = 2147483647;
            int diff = barrier - reversed;
            int max_number = diff / 1000000000;

            cout<<reversed<<endl;
            cout<<diff<<endl;
            cout<<max_number<<endl;
            cout<<s.top()<<endl;

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

            cout<<reversed<<endl;
            cout<<diff<<endl;
            cout<<max_number<<endl;
            cout<<s.top()<<endl;

            if(max_number < s.top())
            {
                return 0;
            }
        }
    }

    return (reversed + multiplier * s.top()) * sign;
}

int main()
{
    cout<<reverse(-214748364);

}

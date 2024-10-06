#include <iostream>

using namespace std;

bool isPowerOfThree(int n)
{
    if(n < 0)
    {
        return false;
    }
    if(n == 0)
    {
        return true;
    }
    int pow = 1;
    int num = 3;
    while(num <= n)
    {
        cout<<num<<endl;
        if(n == num)
        {
            return true;
        }

        num *= 3;
    }
    return false;
}

int main()
{
    isPowerOfThree(27);
    return 0;
}

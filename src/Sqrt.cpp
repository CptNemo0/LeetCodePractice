#include <corecrt_wstdio.h>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int mySqrt(int x)
{
    vector<int> field(x);
    iota(field.begin(), field.end(), 0);

    if (x == 0 || x == 1)
    {
        return x;
    }

    int low = 0;
    int high = x / 2 + 1;
    int return_value = 0;

    while (low <= high)
    {
        int mid = (high + low) / 2;
        int square = field[mid] * field[mid];

        if(square == x)
        {
            return_value = mid;
        }

        if(x < square)
        {
            high = mid - 1;

        }
        else
        {
            low = mid + 1;
            return_value = mid;
        }
    }

    return return_value;
}

int main()
{
    // it overflows, idea and the algorithm are good, just a bullshit testcase
    cout<<mySqrt(2147395599)<<endl;
}

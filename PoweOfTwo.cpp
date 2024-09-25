#include <bitset>
#include <iostream>
bool isPowerOfTwo(int n) 
{
    if(n < 0)
    {
        return false;
    }
 
    int set = 0;
    int last_digit = 0;
    for(int i = 0 ; i < sizeof(int) * 8; i++)
    {
        last_digit = (n & 1);
        if(last_digit == 1)
        {
            set++;
        } 
        n = n >> 1;
    }

    return set == 1;
}

int main()
{
    std::cout<<isPowerOfTwo(16)<<std::endl;
}
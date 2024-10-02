#include<bitset>
#include<iostream>

using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t return_value = 0;

    for(int i = 0 ; i <= 31 ; i++)
    {
        return_value |= ((uint32_t)((n >> 31 - i) & 1) << i);
    }

    return return_value;
}

int main()
{
    reverseBits(127463);
    return 0;
}

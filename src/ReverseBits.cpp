#include<bitset>
#include<iostream>
using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t return_value = 0;

    bitset<32> bits(n);
    bitset<32> new_bits(0);

    for(int i = 0 ; i < 32 ; i++)
    {
        if(bits[31 - i])
        {
            new_bits.set(i);
        }
    }

    cout<<bits.to_string()<<endl;
    cout<<new_bits.to_string()<<endl;

    return new_bits.to_ulong();
}

int main()
{
    reverseBits(127463);
    return 0;
}

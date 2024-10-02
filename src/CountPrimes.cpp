#include <math.h>
#include <vector>
#include <iostream>

int countPrimes(int n)
{
    if(n == 0 || n == 1 || n == 2)
    {
        return 0;
    }

    std::vector <bool> numbers(n - 2,true);

    int ctr = 0;

    for(int i = 2 ; i < n ; i++)
    {
        for(int j = i; j * i< n ; j++)
        {
            numbers[j * i - 2] = false;
        }
    }

    for(int i = 0 ; i < numbers.size() ; i++)
    {
        if(numbers[i])
        {
            std::cout<<"\t"<<i + 2<<"\n";
            ctr++;
        }
        else
        {
            std::cout<<i + 2<<"\n";

        }
    }

    return ctr;
}

int main()
{
    int a = countPrimes(3);

    std::cout<<"\n"<<a<<std::endl;
}

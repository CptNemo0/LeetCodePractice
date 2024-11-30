#include<iostream>

using namespace std;

int climbStairs(int n) 
{
    int one = 1;
    int two = 1;

    for(int i = 0 ; i < n - 1 ; i++)
    {
        auto temp = one;
        one = one + two;
        two = temp;
    }

    return one;
}

int main()
{
    std::cout<<climbStairs(5)<<std::endl;
}
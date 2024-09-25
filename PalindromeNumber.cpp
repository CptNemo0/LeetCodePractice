#include <iostream>

using namespace std;

bool isPalindrome(int x)
{
    if(x < 0)
    {
        return false;
    }

    if(x > -1 && x < 10)
    {
        return true;
    }

    int x_copy = x;
    int return_value = 0;
    int multiplier = 1;
    while(x_copy >= 1)
    {
        int digit = x_copy % 10;
        x_copy = x_copy / 10;

        return_value *= 10;
        return_value += digit;
        
    }

    return (return_value == x);
}

int main()
{
    cout<<isPalindrome(1234567899)<<endl;
    
    return 0;
}
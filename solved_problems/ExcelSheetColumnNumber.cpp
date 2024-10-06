#include <string>
#include <iostream>

using namespace std;

int titleToNumber(string columnTitle)
{
    int return_value = 0;

    int multiplier = 26;

    for(int i = 0 ; i < columnTitle.length() ; i++)
    {
        return_value += (int)(columnTitle[i] - 64) * pow(26 ,columnTitle.length() - i - 1);
    }

    return return_value;
}

int main()
{
    cout<<titleToNumber("AB")<<"\n";
}

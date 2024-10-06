#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> letters {"Z", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y"};

string convertToTitle(int columnNumber)
{
    if(columnNumber <= 0)
    {
        return "";
    }

    int reminder = columnNumber % 26;
    int whole = columnNumber / 26;

    if(!reminder)
    {
        whole -= 1;
    }

    if(whole > 0)
    {
        return convertToTitle(whole) + letters[reminder];
    }
    else
    {
        return letters[reminder];
    }
}

int main()
{
    auto a = convertToTitle(701);
    cout<<a<<endl;
}

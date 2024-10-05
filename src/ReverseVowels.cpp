#include <iostream>
#include <string>
#include <set>
using namespace std;

string reverseVowels(string s)
{
    set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int left = 0;
    int right = s.length() - 1;

    if(left <= right)
    {
        if(left == right)
        {
            break;
        }
    }

    return s;
}

int main()
{

}

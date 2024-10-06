#include <iostream>
#include <string>
#include <set>
using namespace std;

string reverseVowels(string s)
{
    set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int left = 0;
    int right = s.length() - 1;

    while(left < right)
    {
        if(!vowels.contains(s[left]))
        {
            left++;
            continue;
        }

        if(!vowels.contains(s[right]))
        {
            right--;
            continue;
        }

        swap(s[left], s[right]);
        left++;
        right--;
    }

    return s;
}

int main()
{

}

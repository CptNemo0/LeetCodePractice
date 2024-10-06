#include <string>

using namespace std;

bool isPalindrome(string s)
{
    int left = 0;
    int right = s.length() - 1;

    while(left < right)
    {
        char l = s[left];
        char r = s[right];

        if(l > 64 && l < 91)
        {
            s[left] += 32;
        }
        else if((l > 47 && l < 58) || (l > 96 && l < 123))
        {
            l = l;
        }
        else
        {
            left++;
            continue;
        }

        if(r > 64 && r < 91)
        {
            s[right] += 32;
        }
        else if((r > 47 && r < 58) || (r > 96 && r < 123))
        {
            r = r;
        }
        else
        {
            right--;
            continue;
        }

        if(s[left] != s[right])
        {
            return false;
        }
        else
        {
            left++;
            right--;
        }
    }
    return true;
}

int main()
{
    return 0;
}

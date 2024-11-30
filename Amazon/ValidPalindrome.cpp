#include <string>
#include <iostream>

using namespace std;

char toLowerCase(char c)
{
    if(c > 64 && c < 91)
    {
        c += 32;
    }

    return c;
}

bool isAlphanumeric(char c)
{
    if((c > 96 && c < 123) || (c > 47 && c < 58))
    {
        return true;
    }
    return false;
}

bool isPalindrome(string s) 
{
    for(auto& c : s)
    {
        c = toLowerCase(c);
    }

    std::cout<<s<<std::endl;

    int left = 0;
    int right = s.length() - 1;

    while (left <= right)
    {
        std::cout<<"s[left]: "<<s[left]<<" s[right]: "<<s[right]<<std::endl;
        if(!isAlphanumeric(s[left]))
        {
            std::cout<<"left is not alphanumeric"<<std::endl;
            left++;
            continue;
        }

        if(!isAlphanumeric(s[right]))
        {
            std::cout<<"right is not alphanumeric"<<std::endl;
            right--;
            continue;
        }

        if(s[right] != s[left])
        {
            std::cout<<"no match"<<std::endl;
            return false;
        }

        std::cout<<"match"<<std::endl;
        left++;
        right--;
    }

    return true;
}

int main()
{
    printf("%d", isPalindrome("A man, a plan, a canal: Panama"));
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool valid_digit(char a)
{
    return (a >= '0' && a <= '9');
}

int char_to_int(char c)
{
    return (int)(c - 48);
}

int64_t myAtoi(string s)
{
    int n = static_cast<int>(s.size());

    if(n == 0)
    {
        return 0;
    }

    if(n == 1)
    {
        if(!valid_digit(s[0]))
        {
            return 0;
        }
        else
        {
            return char_to_int(s[0]);
        }
    }

    int64_t number = 0;
    int64_t sign = 1;
    int64_t multiplier = 1;
    string s2 = "";
    int a = 0;
    std::vector<int> digits;
    //white space
    

    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] != ' ')
        {
            s2.append(s.substr(i, n));
            break;
        }
    }

    n = static_cast<int>(s2.size());

    if(n == 0)
    {
        return 0;
    }

    if(n == 1)
    {
        if(!valid_digit(s[0]))
        {
            return 0;
        }
        else
        {
            return char_to_int(s[0]);
        }
    }

    if(s2[0] == '0' && !valid_digit(s2[1]))
    {
        return 0;
    }

    //signedness
    if(s2[0] == '-')
    {
        sign = -1;
        a++;
    }
    else if(s2[0] == '+')
    {
        sign = 1;
        a++;
    }
    else if(!valid_digit(s2[0]))
    {
        return 0;
    }

    for(a ; a < n ; a++)
    {
        if(s2[a] == '0' && digits.empty())
        {
            continue;
        }
        
        if(valid_digit(s2[a]))
        {
            digits.push_back(char_to_int(s2[a]));
        }
        else
        {
            break;
        }
    }

    n = static_cast<int>(digits.size());

    if(n > 10)
    {
        if(sign == 1)
        {
            return 2147483647;
        }

        if(sign == -1)
        {
            return -2147483648;
        }
    }

    for(int i = n - 1 ; i > -1 ; i--)
    {
        std::cout<<digits[i]<<std::endl;
        number += multiplier * digits[i];

        if(i != 0)
        {
            multiplier *= 10;
        }
    }

    number *= sign;

    if(number < -2147483648)
    {
        number = -2147483648;
    }
    else if(number > 2147483647)
    {
        number = 2147483647;
    }

    return number;
}

int main()
{
    std::cout<<"GO\n";
    std::cout<<myAtoi("20000000000000000000")<<"\n";
    return 0;
}
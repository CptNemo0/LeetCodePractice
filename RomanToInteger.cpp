#include <string> 

using namespace std;

int romanToInt(string s) 
{
    auto sti = [](char a)
    {
        switch (a)
        {
            case 'I':
            {
                return 1;
                break;
            }
            case 'V':
            {
                return 5;
                break;
            }
            case 'X':
            {
                return 10;
                break;
            }
            case 'L':
            {
                return 50;
                break;
            }
            case 'C':
            {
                return 100;
                break;
            }
            case 'D':
            {
                return 500;
                break;
            }
            case 'M':
            {
                return 1000;
                break;
            }
        }
    };
    
    int return_value = 0;

    int n = static_cast<int>(s.length());

    for(int i = 0 ; i < n - 1; i++)
    {
        if(sti(s[i]) >= sti(s[i + 1]))
        {
            return_value += sti(s[i]);
        }
        else
        {
            return_value -= sti(s[i]);
        }
    }
    
    return_value += sti(s[n - 1]);

    return return_value;
}

int main()
{

}
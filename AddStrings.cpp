#include <iostream>
#include <string>

using namespace std;

string addStrings(string num1, string num2) 
{
    string return_value = "";
    string a;
    string b;

    return_value.reserve(10000 + 1);
    a.reserve(10000 + 1);
    b.reserve(10000 + 1);

    int num1_len = num1.length();
    int num2_len = num2.length();

    int len_a = 0;
    int len_b = 0;

    if(num1_len >= num2_len)
    {
        a = num1;
        len_a = num1_len;

        b = num2;
        len_b = num2_len;
    }
    else
    {
        a = num2;
        len_a = num2_len;

        b = num1;
        len_b = num1_len;
    }

    int diff = len_a - len_b;
    int memory = 0;
    int char_a = 0;
    int char_b = 0;
    int sum = 0;
    int b_idx = 0;
    char new_digit = '0';
    
    for(int a_idx = len_a -1; a_idx > -1 ; a_idx--)
    {
        b_idx = a_idx - diff;
        
        char_a = (int)a[a_idx] - 48;
        char_b = b_idx < 0 ? 0 : (char_b = (int)b[b_idx] - 48);
        
        sum = char_a + char_b + memory;

        if(sum > 9)
        {
            new_digit = (sum - 10) + 48;
            memory = 1;
        }
        else
        {
            new_digit = sum + 48;
            memory = 0;
        }

        return_value.insert(0, 1, new_digit);
    }

    if(memory == 1)
    {
        return_value.insert(0, 1, 49);
    }

    return return_value;
}

int main()
{
    std::cout<<addStrings("1", "9") <<std::endl;
    return 0;
}
#include <iostream>
#include <string>
#include <stack>

std::string reverseWords(std::string& s)
{
    int n = static_cast<int>(s.length());

    std::stack<std::string> words;

    int left = -1;
    int right = -1;
    
    for(int i = 0 ; i < n ; i++)
    {
        char current = s[i];

        if(current == ' ')
        {
            if(left != -1 && right != -1)
            {
                right++;
                words.push(s.substr(left, right - left));
            }

            left = -1;
            right = -1;
            continue;
        }
        else
        {
            if(left == -1 && right == -1)
            {
                left = i;
                right = i;
            }
            else
            {
                right++;
            }
        }
    }

    if(left != -1 && right != -1)
    {
        words.push(s.substr(left, right));
    }

    std::string return_value;
    while(!words.empty())
    {
        return_value += words.top();
        words.pop();
        
        if(!words.empty())
        {
            return_value += " ";
        }
    }

    return return_value;
}

int main()
{
    std::string s = "a good   example";
    std::cout<<reverseWords(s)<<std::endl;
    return 0;
}
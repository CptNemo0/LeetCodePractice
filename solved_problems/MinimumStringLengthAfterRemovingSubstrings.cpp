#include <stack>
#include <string>

using namespace std;

int minLength(string s)
{
    stack<char> characters;

    characters.push(s[0]);

    for(int i = 1 ; i < s.length() ; i++)
    {
        if(characters.empty())
        {
            characters.push(s[i]);
            continue;
        }

        if(s[i] == 'B')
        {
            if(characters.top() == 'A')
            {
                characters.pop();
            }
            else
            {
                characters.push(s[i]);
            }
        }
        else if(s[i] == 'D')
        {
            if(characters.top() == 'C')
            {
                characters.pop();
            }
            else
            {
                characters.push(s[i]);
            }
        }
        else
        {
            characters.push(s[i]);
        }
    }

    return characters.size();
}

int main()
{
    return 0;
}

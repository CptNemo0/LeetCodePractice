#include<string>
#include<unordered_map>
#include<stack>

using namespace std;

bool isValid(string s) 
{
    const unordered_map<char, char> map 
    {
        {'{', '}'},
        {'(', ')'},
        {'[', ']'}
    };

    stack<char> stck;

    for(auto& c : s)
    {
        if(stck.empty())
        {
            if(c == ']' || c == ')' || c == '}')
            {
                return false;
            }
            stck.push(c);
            continue;
        }

        auto top = stck.top();
        if(map.at(top) == c)
        {
            stck.pop();
        }
        else
        {
            if(c == ']' || c == ')' || c == '}')
            {
                return false;
            }
            stck.push(c);
        }
    }

    return stck.empty();
}

int main()
{

}
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

bool isValid(string s)
{   
    int n = static_cast<int>(s.length());

    if(n == 0)
    {
        return true;
    }

    if(n == 1)
    {
        return false;
    }

    unordered_map<char, char> m
    {
        {'(', ')'},
        //{')', '('},
        {'[', ']'},
        //{']', '['},
        {'{', '}'},
        //{'}', '{'}
    };

    stack<char> st;
    
    for(int i = 0 ; i < n ; i++)
    {
        cout<<endl;

        if(st.empty())
        {
            cout<<"pushing current: "<<s[i]<<endl;

            if(s[i] == ')' || s[i] == ']' || s[i] == '}' )
            {
                return false;
            }

            st.push(s[i]);  
            continue;
        }

        char top = st.top();
        char current = s[i];

        cout<<"top: "<<top<<endl;
        cout<<"current: "<<current<<endl;
        
        if(m[top] == current)
        {
            cout<<"popping: "<<top<<endl;
            st.pop();
            continue;
        }
        cout<<"pushing current: "<<current<<endl;
        st.push(current);  
    }

    return st.empty();
}

int main()
{
    cout<<isValid("(){}}{")<<endl;
}
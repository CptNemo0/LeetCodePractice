#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) 
{
    int n = static_cast<int>(temperatures.size());

    vector<int> return_value(n, 0);
    stack <int> s;

    for(int i = 0 ; i < n ; i++)
    {
        if(s.empty())
        {
            s.push(i);
        }
        else
        {
            while(!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                auto popped = s.top();
                s.pop();

                return_value[popped]++;

                if(!s.empty())
                {
                    return_value[s.top()] += return_value[popped];
                }
            }

            s.push(i);
        }
        
    }

    while(!s.empty())
    {
        auto popped = s.top();
        s.pop();
        return_value[popped] = 0;
    }

    return return_value;
}

int main()
{
    vector<int> c = {30,60,90};
    
    cout<<"GO\n";
    auto a = dailyTemperatures(c);
    cout<<"GO\n";
    for(auto b : a)
    {
        cout<<b<<endl;
    }
}
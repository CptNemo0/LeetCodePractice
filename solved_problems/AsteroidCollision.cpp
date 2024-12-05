#include "minclude.h"

class Solution
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        vector<int> return_value;
        vector<int> q;
        
        for(auto& asteroid : asteroids)
        {
            if(q.empty())
            {
                if(asteroid < 0) 
                {
                    return_value.push_back(asteroid);
                }
                else
                {
                    q.push_back(asteroid);
                }
                continue;
            }

            if(asteroid > 0)
            {
                q.push_back(asteroid);
            }
            else
            {
                while(true)
                {
                    if(q.empty())
                    {
                        return_value.push_back(asteroid);
                        break;
                    }
                    else
                    {
                        if(abs(asteroid) > q.back())
                        {
                            q.pop_back();
                        }
                        else if(abs(asteroid) == q.back())
                        {
                            q.pop_back();
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }

        for(auto& e : q)
        {
            return_value.push_back(e);
        }

        return return_value;
    }
};

int main()
{
    Solution s {};

    vector<int> input {5, 10, -5};
    vector<int> output = s.asteroidCollision(input);
    for(auto& e : output)
    {
        cout<<e<<" ";
    }
    return 0;
}
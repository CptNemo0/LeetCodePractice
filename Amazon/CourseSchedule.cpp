#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> child_of(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for(const auto& v : prerequisites)
        {
            int course = v[1];
            int prerequisite = v[0];

            graph[prerequisite].push_back(course);
            child_of[course]++;
        }

        queue<int> no_prerequisites;

        for(int i = 0 ; i < numCourses ; i++)
        {
            if(child_of[i] != 0) continue;
            no_prerequisites.push(i);
        }

        vector<int> return_value;
        return_value.reserve(numCourses);

        while(!no_prerequisites.empty())
        {
            int current = no_prerequisites.front();
            no_prerequisites.pop();
            return_value.push_back(current);
            if(return_value.size() > numCourses) return {};

            for(auto& course : graph[current])
            {
                if(--child_of[course]) continue;
                no_prerequisites.push(course);
            }
        }

        reverse(return_value.begin(), return_value.end());

        return return_value;
    }
};
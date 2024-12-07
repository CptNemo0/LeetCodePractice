#include "minclude.h"

class Interval 
{
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution 
{
public:
    int minMeetingRooms(vector<Interval>& intervals) 
    {
        priority_queue<int, vector<int>, greater<int>> starts;
        priority_queue<int, vector<int>, greater<int>> ends;

        for(auto& interval : intervals)
        {
            starts.push(interval.start);
            ends.push(interval.end);
        }

        int count = 0;
        int return_value = 0;
        while(!starts.empty() && !ends.empty())
        {
            if(starts.top() < ends.top())
            {
                starts.pop();
                count--;
            }
            else
            {
                ends.pop();
                count--;
            }
            return_value = max(count, return_value);
        }

        return return_value;
    }
};

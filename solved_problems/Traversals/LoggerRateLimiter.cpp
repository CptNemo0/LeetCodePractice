#include "minclude.h"

class Logger
{
    unordered_map<string, int> map;

    void shouldPrintMessage(int timestamp, string message)
    {
        if(!map.contains(message))
        {
            map[message] = timestamp + 10;
            cout<<message<<endl;
        }
        else
        {
            if(timestamp >= map[message])
            {
                map[message] = timestamp + 10;
                cout<<message<<endl;
            }
        }
    }
};
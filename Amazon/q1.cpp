#include<string>
#include<vector>

using namespace std;

string findNumber(vector<int> numbers) 
{
    string return_value = "";

    vector<int> odd_collection (numbers.begin(), numbers.end());
    vector<int> even_collection;

    int level = 1;
    int iterations = numbers.size() - 1;

    auto new_level = [](vector<int>& origin, vector<int>& dest)
    {
        dest.clear();
        int n = origin.size();
        for(int i = 0; i < n - 1; i++)
        {
            int sum = (origin[i] + origin[i + 1]);
            int digit = sum % 10;
            dest.emplace_back(digit);
        }
    };

    for(int _ = 0 ; _ < iterations ; _++)
    {
        if(level & 1) //odd collection is origin
        {
            if(odd_collection.size() == 2) 
            {
                return_value = to_string(odd_collection[0]) + to_string(odd_collection[1]);
                return return_value;
            }
            new_level(odd_collection, even_collection);
        }
        else //even collection is origin
        {
            if(even_collection.size() == 2) 
            {
                return_value = to_string(even_collection[0]) + to_string(even_collection[1]);
                return return_value;
            }
            new_level(even_collection, odd_collection);
        }
        level++;
    }

    return return_value;
}

int main()
{
    return 0;
}
#include<iostream>
#include<set>
#include<vector>

using namespace std;

void get_digits(int n, vector<int>& vec)
{
    while(n > 0)
    {
        int digit = n % 10;
        vec.push_back(digit);
        n /= 10;
    }
}

int get_square_sum(vector<int>& vec)
{
    int sum = 0;
    
    for(auto& e : vec)
    {
        sum += e * e;
    }

    return sum;
}

bool isHappy(int n) 
{
    set<int> visited;
    vector<int> vec (10);

    while(!visited.contains(n))
    {
        visited.insert(n);
        vec.clear();
        get_digits(n, vec);
        n = get_square_sum(vec);

        if(n == 1)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> d;
    get_digits(121312, d);

    for(auto c : d)
    {
        std::cout<<c;
    }
    
    return 0;
}
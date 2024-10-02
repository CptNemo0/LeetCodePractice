#include <vector>
#include<set>
using namespace std;

vector<int> get_digits(int n)
{
    vector<int> return_value;

    while(n >= 1)
    {
        return_value.push_back(n % 10);
        n /= 10;
    }

    return return_value;
}

int get_new_number(vector<int>& digits)
{
    int return_value = 0;

    for(auto a : digits)
    {
        return_value += a * a;
    }

    return return_value;
}

bool isHappy(int n)
{
    if(n == 1)
    {
        return true;
    }

    set<int> s;
    s.insert(n);
    while (true)
    {
        auto digits = get_digits(n);
        n = get_new_number(digits);

        if(n == 1)
        {
            return true;
        }

        if(s.contains(n))
        {
            return false;
        }

        s.insert(n);
    }
}

int main()
{

}

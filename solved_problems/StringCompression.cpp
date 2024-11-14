#include <vector>
#include <string>
#include <iostream>

using namespace std;

int compress(vector<char>& chars)
{
    int left = 0;
    int right = 0;
    int n = chars.size();

    if(n == 1)
    {
        return 1;
    }

    auto lambda = [&chars](int& left, int& right, int difference, int& n)
    {
        auto it_hint = chars.erase(chars.begin() + left + 1, chars.begin() + right);

        string difference_s = std::to_string(difference);
        int difference_s_len = difference_s.length();

        for(auto& c : difference_s)
        {
            chars.insert(it_hint, c);
            it_hint = std::next(it_hint);
        }
        n = chars.size() ;
        left += difference_s_len + 1;
        right = left;
    };

    while(left < n && right < n)
    {
        if(chars[left] != chars[right])
        {
            int difference = right - left;

            if(difference > 1)
            {
                lambda(left, right, difference, n);
                continue;
            }

            left++;
            right++;
        }
        else
        {
            right++;

            if(right >= n)
            {
                int difference = right - left;
                if(difference > 1)
                {
                    lambda(left, right, difference, n);
                }
            }
        }
    }
    
    return chars.size();
}


int main()
{
    vector<char> v {'a','b', 'b', 'b', 'b', 'b', 'x','b', 'b', 'b', 'b', 'b', 'b', 'b', 'c', 'c'};

    compress(v);

    for(auto a : v)
    {
        cout<<a<<" ";
    }
    cout<<"\n";

    return 0;
}

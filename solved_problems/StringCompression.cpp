#include <vector>
#include <string>
#include <iostream>

using namespace std;

int compress(vector<char>& chars)
{
    int left = 0;
    int right = 0;
    int n = chars.size() ;

    if(n == 1)
    {
        return 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(auto a : chars)
        {
            cout<<a;
        }
        cout<<"\n";

        cout<<"left : "<<left<<endl;
        cout<<"right: "<<right<<endl;
        cout<<"i    : "<<i<<endl;
        cout<<"n    : "<<n<<endl;
        if(chars[left] == chars[right])
        {
            right++;
        }
        else
        {
            int count = right - left;
            cout<<"\t"<<count<<" "<<chars[left]<<"\n";
            if(count == 1)
            {
                cout<<"left++"<<endl;
                left++;
                right = left;
                i = right;
                n = chars.size();
                continue;
            }
            chars.erase(chars.begin() + left + 1, chars.begin() + right);
            string count_str = to_string(count);
            for(int j = 0 ; j < count_str.length() ; j++)
            {
                left++;
                chars.insert(chars.begin() + left, count_str[j]);
            }
            left++;
            right = left ;
            i = right;
            n = chars.size();
        }
    }

    cout<<"\nleft : "<<left<<endl;
    cout<<"right: "<<right<<endl;
    cout<<"n    : "<<n<<endl;
    right++;
    if(right - left > 1)
    {
        if(left == 0)
        {
            right--;
        }
        chars.erase(chars.begin() + left + 1, chars.begin() + right);
        int count = right - left;
        if(count == 1)
        {
            return chars.size();
        }
        string count_str = to_string(count);

        for(int j = 0 ; j < count_str.length() ; j++)
        {
            chars.push_back(count_str[j]);
        }
    }

    return chars.size();
}


int main()
{
    vector<char> v {'a', 'b', 'c'};

    compress(v);

    for(auto a : v)
    {
        cout<<a<<" ";
    }
    cout<<"\n";

    return 0;
}

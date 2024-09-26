#include <string>
#include <iostream>
#include <sstream>

using namespace std;

string addBinaryHelper(string a, string b)
{
    stringstream return_value;
    int len_a = a.length();
    int len_b = b.length();
    int difference = len_a - len_b;

    int memory = 0;
    for(int idx_a = len_a - 1; idx_a > -1 ; idx_a--)
    {
        int idx_b = idx_a - difference;

        int ia = a[idx_a] - 48;
        int ib = idx_b > -1 ? b[idx_b] - 48 : 0 ;

        cout<<"idx_a: "<<idx_a<<endl;
        cout<<"idx_b: "<<idx_b<<endl;

        cout<<"ia: "<<ia<<endl;
        cout<<"ib: "<<ib<<endl;
        cout<<"memory: "<<ib<<endl;

        int addition = ia + ib + memory;
        int result = addition % 2;
        if(addition / 2 >= 1)
        {
            memory = 1;
        }
        else
        {
            memory = 0;
        }
        return_value << result;
    }

    if(memory)
    {
        return_value << 1;
    }

    string n = return_value.str();
    string r(n.rbegin(), n.rend());
    return r;
}

string addBinary(string a, string b)
{
    if(a.length() > b.length())
    {
        return (addBinaryHelper(a, b));
    }
    else
    {
        return (addBinaryHelper(b, a));
    }
}

int main()
{
    cout<<addBinary("11", "1");
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    int n = static_cast<int>(digits.size());

    int idx = n - 1;
    int memory = 1;

    while(memory)
    {
        if(idx == -1)
        {
            digits.insert(digits.begin(), 1);
            memory = 0;
            cout<<"inserting 1 at the begining\n";
            break;
        }
        if(digits[idx] < 9)
        {
            cout<<"adding 1 to "<<digits[idx]<<"\n";
            digits[idx]++;
            memory = 0;
            break;
        }
        else
        {
            cout<<"replacing 9 with 0 \n";
            digits[idx] = 0;
            memory = 1;
            idx--;
        }
    }

    return digits;
}

int main()
{
    vector<int> digits {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};

    plusOne(digits);

    for(auto d : digits)
    {
        cout<<d;
    }
    cout<<"\n";
    return 0;
}

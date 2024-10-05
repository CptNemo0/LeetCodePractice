#include <vector>

using namespace std;

void reverseString(vector<char>& s)
{
    int left = 0;
    int right = s.size() - 1;

    while(left <= right)
    {
        if(left == right)
        {
            break;
        }

        swap(s[left], s[right]);
        left++;
        right--;
    }
}

int main()
{

}

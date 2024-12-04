#include<vector>
#include<iostream>

using namespace std;

void merge(vector<int>& arr, int left, int middle, int right)
{
    vector<int> left_arr (arr.begin() + left, arr.begin() + middle + 1);
    vector<int> right_arr (arr.begin() + middle + 1, arr.begin() + right + 1);

    cout<<"Merge\nleft_arr:";
    for(auto e : left_arr)
    {
        cout<<" "<<e;
    }
    cout<<" left_arr.size(): "<<left_arr.size();
    cout<<"\nright_arr:";
    for(auto e : right_arr)
    {
        cout<<" "<<e;
    }
    cout<<" right_arr.size(): "<<right_arr.size()<<"\n";
    int l = 0;
    int r = 0;
    int m = left;

    while(l < left_arr.size() && r < right_arr.size())
    {
        if(left_arr[l] <= right_arr[r])
        {
            arr[m] = left_arr[l];
            l++;
        }
        else
        {
            arr[m] = right_arr[r];
            r++;
        }
        m++;
    }

    while(l < left_arr.size())
    {
        arr[m] = left_arr[l];
        l++;
        m++;
    }

    while(r < right_arr.size())
    {
        arr[m] = right_arr[r];
        r++;
        m++;
    }

    cout<<"After merge:";
    for(auto e : arr)
    {
        cout<<" "<<e;
    }
    cout<<"\n";
}

vector<int> merge_sort(vector<int>& arr, int left, int right)
{
    if (left == right) return arr;
    int middle = left + (right - left) / 2;
    merge_sort(arr, left, middle);
    merge_sort(arr, middle + 1, right);
    merge(arr, left, middle, right);
    return arr;
}

int main()
{
    vector<int> a {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0, -1,0};
    merge_sort(a, 0, a.size() - 1);
}
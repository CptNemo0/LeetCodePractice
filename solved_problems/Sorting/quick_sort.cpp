#include<vector>
#include<iostream>

using namespace std;

int partition(vector<int>& arr, int left, int right)
{
    //cout<<"left: "<<left<<" right: "<<right<<endl;
    
    int pivot = arr[right];
    int i = left;
    
    for(int j = left ; j < right ; j++)
    {
        if(arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            for(auto e : arr)
            {
                cout<<" "<<e;
            }
            cout<<"\n";
            i++;
        }
    }

    swap(arr[i], arr[right]);
    for(auto e : arr)
    {
        cout<<" "<<e;
    }
    cout<<"\n";
    return i;
}


void quick_sort(vector<int>& arr, int left, int right)
{
    //cout<<"\nBefore sorting: ";
    //for(auto e : arr)
    //{
    //    cout<<" "<<e;
    //}
    //cout<<"\n";

    if(arr.empty()) return;
    if(left >= right || left < 0) return;

    int p = partition(arr, left, right);

    quick_sort(arr, left, p - 1);
    quick_sort(arr, p + 1, right);

    //cout<<"After sorting: ";
    //for(auto e : arr)
    //{
    //    cout<<" "<<e;
    //}
    //cout<<"\n";
}

int main()
{
    vector<int> a {-1,2,-8,-10};
    quick_sort(a, 0, a.size() - 1);
    for(auto e : a)
    {
        cout<<" "<<e;
    }

}

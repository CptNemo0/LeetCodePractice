#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class MedianFinder 
{
public:
    vector<int> data;
    MedianFinder() 
    {
        data.reserve(5000);
    }

    void addNum(int num) 
    {
        auto it = upper_bound(data.begin(), data.end(), num);
        data.insert(it, num);
    }
    
    double findMedian() 
    {
        if(data.size() == 1) return data[0];
        int left = 0;
        int right = data.size() - 1;
        int mid = left + (right - left) / 2;
        
        if(data.size() & 1)
        {
            return static_cast<double>(data[mid]);
        }
        return static_cast<double>(data[mid] + data[mid + 1]) / 2.0;
    }

    void Log()
    {
        cout<<"Log: \n\t";
        for(auto& d : data)
        {
            cout<<d<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    MedianFinder f {};
    f.addNum(-1);
    f.Log();
    f.addNum(-2);
    f.Log();
    f.addNum(-3);
    f.Log();
    f.addNum(-4);
    f.Log();
    f.addNum(-5);
    f.Log();
    cout<<f.findMedian()<<endl;
}
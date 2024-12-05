#include "minclude.h"

vector<int> solution(vector<int>& vec)
{
    vector<int> return_value;

    return_value.push_back(vec.size() - 1);
    
    for(int i = vec.size() - 2 ; i > -1 ; i--)
    {
        cout<<"return_value.back(): "<<return_value.back()<<" vec[i]:"<<vec[i]<<"\n";
        if(vec[return_value.back()] < vec[i]) 
        {
            return_value.push_back(i);
        }
    }
   
    reverse(return_value.begin(), return_value.end());  
    return return_value;
}

int main()
{
    vector<int> a {2, 2, 2, 2};
    auto result = solution(a);
    for(auto& e : result)
    {
        cout<<e<<endl;
    }
    return 0;
}
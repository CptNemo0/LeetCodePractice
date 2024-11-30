#include<vector>
#include<queue>
#include<iostream>

using namespace std;

struct Row
{
    int idx;
    int power= 0;

    Row(int i, vector<int>& v)
    {
        idx = i;
        for(auto& a : v)
        {
            if(a == 1) this->power++;
            cout<<a<<" ";
        }
        cout<<"\n";
    }
    
    void Log()
    {
        cout<<"idx: "<<idx<<" power: "<<power<<endl;
    }
};

class Solution 
{
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        auto sorting_lambda = [](Row& i, Row& j)
        {
            if(i.power != j.power) return i.power > j.power;
            return i.idx > j.idx;
        };

        priority_queue<Row, vector<Row>, decltype(sorting_lambda)> q(sorting_lambda);

        for(int i = 0 ; i < mat.size() ; i++)
        {
            q.push(Row(i, mat[i]));
        }

        vector<int> return_value;

        while(!q.empty())
        {
            auto row = q.top();
            q.pop();
            row.Log();
        }

        //for(int i = 0 ; i < k ; i++)
        //{
        //    return_value.push_back(q.top().idx);
        //    q.pop();    
        //}

        return return_value;
    }
};

int main()
{
    vector<vector<int>> v {{1,1,0,0,0},
                           {1,1,1,1,0},
                           {1,0,0,0,0},
                           {1,1,0,0,0},
                           {1,1,1,1,1}};
    Solution s {};
    s.kWeakestRows(v, 3);
    return 0;
}
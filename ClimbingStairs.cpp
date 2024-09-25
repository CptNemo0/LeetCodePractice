#include <stack>
#include <iostream>
#include <set>
#include <queue>
#include <vector>

struct Node
{
    Node* left; // +1
    Node* right; // +2

    int stair_num;

    Node(int n) : stair_num(n), left(nullptr), right(nullptr){};
};

int climbStairs(int n) 
{
    int return_value = 0;
    std::queue<int> q1;
    std::queue<int> q2;
    q2.push(0);

    for(int i = 0 ; i < n - 1; i++)
    {
        if(i & 1)
        {
            while(!q1.empty())
            {
                int front = q1.front();

                int left = front + 1;
                int right = front + 2;

                if(left == n)
                {
                    return_value++;
                }
                else
                {
                    if(left < n)
                    {
                        q2.push(left);
                    }
                }

                if(right == n)
                {
                    return_value++;
                }
                else
                {
                    if(right < n)
                    {
                        q2.push(right);
                    }
                }   
           
                q1.pop();
            }
        }
        else
        {
            while(!q2.empty())
            {
                int front = q2.front();

                int left = front + 1;
                int right = front + 2;

                if(left == n)
                {
                    return_value++;
                }
                else
                {
                    if(left < n)
                    {
                        q1.push(left);
                    }
                }

                if(right == n)
                {
                    return_value++;
                }
                else
                {
                    if(right < n)
                    {
                        q1.push(right);
                    }
                }   

                q2.pop();
            }
        }
    }

    return ++return_value;
}

int main()
{
    std::cout<<"GO\n";
    std::cout<<climbStairs(44)<<std::endl;
}
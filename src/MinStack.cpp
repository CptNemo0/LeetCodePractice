#include <stack>

using  namespace std;

class MinStack
{
public:
    stack<int64_t> data_;
    int64_t min_value_;

    MinStack()
    {

    }

    void push(int val)
    {
        int64_t internal_val = static_cast<int64_t>(val);
        if(data_.empty())
        {
            data_.push(internal_val);
            min_value_ = internal_val;
        }
        else
        {
            if(val < min_value_)
            {
                int64_t to_push = 2 * internal_val - min_value_;
                data_.push(to_push);
                min_value_ = internal_val;
            }
            else
            {
                data_.push(internal_val);
            }
        }
    }

    void pop()
    {
        if(data_.top() < min_value_)
        {
            min_value_ = 2 * min_value_ - data_.top(); 
            data_.pop();
        }
        else
        {
            data_.pop();
        }
    }

    int top()
    {
        if(data_.top() < min_value_)
        {
            return static_cast<int>(min_value_);
        }
        else
        {
            return static_cast<int>(data_.top());
        }
    }

    int getMin()
    {
        return static_cast<int>(min_value_);
    }
};

int main()
{

}

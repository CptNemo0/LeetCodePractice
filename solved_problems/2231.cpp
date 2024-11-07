#include<vector>
#include<iostream>
#include<algorithm>

int largestInteger(int num) 
{
    std::vector<int> digits;
    std::vector<int> odd;
    std::vector<int> idx_odd;
    std::vector<int> even;
    std::vector<int> idx_even;

    while(num > 0)
    {
        int d = num % 10;
        num = num / 10;
        digits.push_back(d);
    }        
    
    std::reverse(digits.begin(), digits.end());

    for(auto d : digits)
    {
        std::cout<<d;
    }

    std::cout<<"\n";

    for(int i = 0 ; i < digits.size() ; i++)
    {
        if(digits[i] & 1)
        {
            odd.push_back(digits[i]);
            idx_odd.push_back(i);
        }
        else
        {
            even.push_back(digits[i]);
            idx_even.push_back(i);
        }
    }
    
    std::cout<<"odd: \n";
    for(auto o : odd)
    {
        std::cout<<o<<std::endl;
    }

    std::cout<<"even: \n";
    for(auto o : even)
    {
        std::cout<<o<<std::endl;
    }

    auto sorting_lambda = [](int a, int b)
    {
        return a > b;
    };

    std::sort(odd.begin(), odd.end(), sorting_lambda);
    std::sort(even.begin(), even.end(), sorting_lambda);
    std::cout<<"odd: \n";

    for(auto o : odd)
    {
        std::cout<<o<<std::endl;
    }

    std::cout<<"even: \n";
    for(auto o : even)
    {
        std::cout<<o<<std::endl;
    }


    std::vector<int> final_number_v (digits.size());

    for(int i = 0 ; i < odd.size() ; i++)
    {
        final_number_v[idx_odd[i]] = odd[i];
    }

    for(int i = 0 ; i < even.size() ; i++)
    {
        final_number_v[idx_even[i]] = even[i];
    }

    int return_value = 0;
    int multiplier = 1;
    for (int i = final_number_v.size() -1; i > -1 ; i--)
    {
        return_value += multiplier * final_number_v[i];
        multiplier *= 10;
    }

    std::cout<<return_value<<std::endl;

    return return_value;
}

int main()
{
    largestInteger(139);
    return 0;
}
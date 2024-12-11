#include "minclude.h"

class Solution 
{
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        if (n == 0) return 1;
        if (n == 1) return 10;

        unordered_map<int, unordered_set<int>> digits_of;
        unordered_set<int> has_unique;

        for(int i = 0 ; i < 10 ; i++)
        {
            digits_of[i].insert(i);
            has_unique.insert(i);
        }

        int ceil = pow(10, n);

        auto solve = [&digits_of, &has_unique](int n)
        {
            int last_digit = n % 10;
            int first_digits = n / 10;

            if(has_unique.contains(first_digits) && !digits_of[first_digits].contains(last_digit))
            {
                has_unique.insert(n);
                digits_of[n] = unordered_set<int>(digits_of[first_digits].begin(), digits_of[first_digits].end());
                digits_of[n].insert(last_digit);
                return true;
            }
            return false;
        };

        for(int i = 10 ; i < ceil ; i++)
        {
            solve(i);
        }

        return has_unique.size();
        
    }
};
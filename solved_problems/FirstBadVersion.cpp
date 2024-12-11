bool isBadVersion(int version) 
{
    return true;
}

class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        int left = 1;
        int right = n;

        if(isBadVersion(left)) return 1; 
        
        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(isBadVersion(mid))
            {
                right = mid;
                continue;
            }
            else
            {
                left = mid;
                continue;
            }
        }

        return left;
    }
};
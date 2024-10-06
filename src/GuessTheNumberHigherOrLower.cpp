int guess(int num)
{
    return 0;
}

int guessNumber(int n)
{
    int low = 0;
    int high = n;

    while(low <= high)
    {
        if(low == high)
        {
            return low;
        }

        int mid = (low + high) / 2;

        if(guess(mid) == 0)
        {
            return 0;
        }

        if(guess(mid) == -1)
        {
            high = mid - 1;
        }

        if(guess(mid) == 1)
        {
            low = mid + 1;
        }
    }
}

int main()
{

}

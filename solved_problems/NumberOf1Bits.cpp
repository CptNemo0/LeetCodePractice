int hammingWeight(int n)
{
    uint32_t return_value = 0;

    for(int i = 0 ; i <= 31 ; i++)
    {
        if((n >> i) & 1)
        {
            return_value++;
        }
    }

    return return_value;
}

int main()
{

}

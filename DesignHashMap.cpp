const int max_size = 1000001;

class MyHashMap 
{
private:    
    
    int values_[max_size];

public:

    MyHashMap() 
    {
        for(int i = 0; i < max_size ; i++)
        {
            values_[i] = -1;
        }
    }
    
    void put(int key, int value) 
    {
        values_[key] = value;
    }
    
    int get(int key) 
    {
        return values_[key];
    }
    
    void remove(int key) 
    {
        values_[key] = -1;
    }
};

int main()
{
    return 0;
}
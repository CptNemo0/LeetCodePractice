#include<iostream>
#include<concepts>
#include <chrono>
#include<vector>

#define INITIAL_CAPACITY 100

using namespace std;
using namespace std::chrono;

template <typename T>
concept Streamable = requires(T t, std::ostream& os) {
    os << t;
};

template <Streamable T>
class List
{
public:   
    T* data = nullptr;
    int capacity = INITIAL_CAPACITY;
    int size = 0;
    
    List()
    {
        reallocate();
    }

    List(size_t new_capacity)
    {
        reserve(new_capacity);
    }

    ~List()
    {
        free(data);
    }
    
    void reserve(size_t new_capacity)
    {
        if(new_capacity == 0) new_capacity = 1;
        if(new_capacity <= size) return;   
        capacity = new_capacity;
        reallocate();
    }

    void reallocate()
    {
        size_t s_T = sizeof(T);
        T* new_data = reinterpret_cast<T*>(calloc(s_T, capacity));
        memcpy(new_data, data, size * s_T);
        free(data);
        data = new_data;
    }

    void push_back(const T& element)
    {
        if(size == capacity)
        {
            capacity *= 2;
            reallocate();
        }

        data[size] = element;
        size++;
    }

    void insert(int position, const T& value)
    {
        if(size == capacity)
        {
            capacity *= 2;
            reallocate();
        }

        size_t s_T = sizeof(T);
        size_t to_copy = (size - position) * s_T;
        memcpy(data + position + 1, data + position, to_copy);
        data[position] = value;
        size++;
    }

    
    void erase(int position)
    {
        size_t s_T = sizeof(T);
        size_t to_copy = (size - (position + 1)) * s_T;
        memcpy(data + position, data + position + 1, to_copy);
        size--;
    }

    T& operator [] (int idx)
    {
        return data[idx];
    }

    void Log(bool print = false)
    {
        std::cout<<"size: "<<size<<"\n";
        std::cout<<"capacity: "<<capacity<<"\n";
        if(!print) return;
        for(int i = 0 ; i < size ; i++)
        {
            std::cout<<data[i]<<", ";
        }
        std::cout<<"\n";
    }
};

int main()
{
    List<int>     my_ints {10};
    vector<int> ints {10};

    std::cout<<"================\n";
    std::cout<<"Allocation test:\n";

    double my_time = 0.0;
    double vector_time = 0.0;

    for(int j = 0 ; j < 10 ; j++)
    {
        steady_clock::time_point allocation_start = steady_clock::now();

        for(int i = 0 ; i < 10000000 ; i++)
        {
            ints.push_back(i);
        }

        steady_clock::time_point allocation_end = steady_clock::now();

        steady_clock::time_point allocation_start_m = steady_clock::now();

        for(int i = 0 ; i < 10000000 ; i++)
        {
            my_ints.push_back(i);
        }

        steady_clock::time_point allocation_end_m = steady_clock::now();
        
        my_time +=  static_cast<double>(duration_cast<milliseconds>(allocation_end_m - allocation_start_m).count());
        vector_time += static_cast<double>(duration_cast<milliseconds>(allocation_end - allocation_start).count());
    }
    
    my_time *= 0.1;
    vector_time *= 0.1;

    cout << "My list = " << my_time << "[ms]\n";
    cout << "Vector = " <<  vector_time << "[ms]\n";
    
    std::cout<<"================\n";
    std::cout<<"Insert test:\n";
    
    my_time *= 0.0;
    vector_time *= 0.0;

    List<int>     my_ints_2 {10000};
    vector<int> ints_2 {10000};

    for(int i = 0 ; i < 100 ; i++)
    {
        ints_2.push_back(i);
        my_ints_2.push_back(i);
    }

    for(int j = 0 ; j < 10 ; j++)
    {
        steady_clock::time_point allocation_start = steady_clock::now();

        for(int i = 0 ; i < 20000 ; i++)
        {
            ints_2.insert(ints_2.begin() + i,  i);
        }

        steady_clock::time_point allocation_end = steady_clock::now();

        steady_clock::time_point allocation_start_m = steady_clock::now();

        for(int i = 0 ; i < 20000 ; i++)
        {
            my_ints_2.insert(i, i);
        }

        steady_clock::time_point allocation_end_m = steady_clock::now();
        
        my_time +=  static_cast<double>(duration_cast<milliseconds>(allocation_end_m - allocation_start_m).count());
        vector_time += static_cast<double>(duration_cast<milliseconds>(allocation_end - allocation_start).count());
    }

    my_time *= 0.1;
    vector_time *= 0.1;

    cout << "My list = " << my_time << "[ms]\n";
    cout << "Vector = " <<  vector_time << "[ms]\n";

    std::cout<<"================\n";
    std::cout<<"Erase test:\n";
    
    my_time *= 0.0;
    vector_time *= 0.0;    

    for(int j = 0 ; j < 10 ; j++)
    {
        steady_clock::time_point allocation_start = steady_clock::now();

        for(int i = 20000 ; i > 0 ; i--)
        {
            ints_2.erase(ints_2.begin() + i);
        }

        steady_clock::time_point allocation_end = steady_clock::now();

        steady_clock::time_point allocation_start_m = steady_clock::now();

        for(int i = 20000 ; i > 0 ; i--)
        {
            my_ints_2.erase(i);
        }

        steady_clock::time_point allocation_end_m = steady_clock::now();
        
        my_time +=  static_cast<double>(duration_cast<milliseconds>(allocation_end_m - allocation_start_m).count());
        vector_time += static_cast<double>(duration_cast<milliseconds>(allocation_end - allocation_start).count());
    }

    my_time *= 0.1;
    vector_time *= 0.1;

    cout << "My list = " << my_time << "[ms]\n";
    cout << "Vector = " <<  vector_time << "[ms]\n";

    return 0;
}
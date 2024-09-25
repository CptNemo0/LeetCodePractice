#include <map>
#include <set>
#include <vector>
#include <array>

using namespace std;

class LRUCache 
{
private:
    map<int, int> key_idx_map_;
    set<int> key_set_;
    
    int* values_;
    int* recency_;

    int recency_counter_ = -1;
    int max_size_;
    int current_size = 0;
        
public:
    LRUCache(int capacity) 
    {
        max_size_ = capacity;
        values_ = (int*)malloc(capacity * sizeof(int));
        recency_ = (int*)malloc(capacity * sizeof(int));
        
        for(int i = 0 ; i < capacity ; i++)
        {
            values_[i] = -1;
            recency_[i] = -1;
        }
    }
    
    ~LRUCache() 
    {
        free(values_);
        free(recency_);
    }

    int get(int key) 
    {
        recency_counter_++;
        if(!key_set_.contains(key))
        {
            return -1;
        }
        else
        {   
            recency_[key_idx_map_[key]] = recency_counter_;
            return values_[key_idx_map_[key]];
        }
    }
    
    void put(int key, int value) 
    {
        recency_counter_++;

        if(key_set_.contains(key))
        {
           values_[key_idx_map_[key]] = value;
           recency_[key_idx_map_[key]] = recency_counter_;
        }

        else
        {
            if(current_size < max_size_)
            {
                current_size++;
                int idx = current_size - 1;
                key_idx_map_.emplace(key, idx);
                key_set_.insert(key);
                values_[idx] = value;
                recency_[idx] = recency_counter_;
            }
            else if(current_size == max_size_)
            {
                //find least recent
                int lru = 99999999;
                int lru_key = -1;
                int lru_idx = -1;

                for(const auto& [key_, value] : key_idx_map_)
                {
                    if(recency_[value] < lru)
                    {
                        lru = recency_[value];
                        lru_key = key_;
                        lru_idx = value;
                    }
                }
                
                
                key_idx_map_.erase(lru_key);
                key_set_.erase(lru_key);

                int idx = lru_idx;
                key_idx_map_.emplace(key, idx);
                key_set_.insert(key);
                values_[idx] = value;
                recency_[idx] = recency_counter_;
            }
        }
    }
};
int main()
{
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    lRUCache->get(1);    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache->get(2);    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache->get(1);    // return -1 (not found)
    lRUCache->get(3);    // return 3
    lRUCache->get(4);    // return 4
}
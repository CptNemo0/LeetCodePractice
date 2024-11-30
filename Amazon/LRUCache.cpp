#include<unordered_map>
#include<queue>

using namespace std;

class LRUCache 
{    
public:
    int ctr_;
    int size_;
    int capacity_;
    
    deque<pair<int, int>> q_;
    unordered_map<int, int> id_val_;
    unordered_map<int, int> id_freq_;

    LRUCache(int capacity) 
    {
        ctr_ = 0;
        capacity_ = capacity;
        size_ = 0;
    }
     
    int get(int key) 
    {
        ctr_++;

        if(!size_) return -1;
        if(!id_val_.contains(key)) return -1;
        
        id_freq_[key] = ctr_;
        q_.emplace_back(key, ctr_);

        return id_val_[key];
    }
         
    void put(int key, int value) 
    {
        ctr_++;
        
        if(id_val_.contains(key))
        {
            id_val_[key] = value;
            id_freq_[key] = ctr_;

            q_.emplace_back(key, ctr_);

            return;
        }

        if(size_ < capacity_)
        {
            size_++;
            id_val_.emplace(key, value);
            id_freq_.emplace(key, ctr_);
            q_.emplace_back(key, ctr_);
        }
        else
        {
            while(q_.size())
            {
                auto [k, f] = q_.front();
                q_.pop_front();

                if(f == id_freq_[k])
                {
                    auto ivit = id_val_.find(k);
                    auto ifit = id_freq_.find(k);
                    id_val_.erase(ivit);
                    id_freq_.erase(ifit);

                    id_val_.emplace(key, value);
                    id_freq_.emplace(key, ctr_);
                    q_.emplace_back(key, ctr_);
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }
};

int main()
{
    return 0;
}
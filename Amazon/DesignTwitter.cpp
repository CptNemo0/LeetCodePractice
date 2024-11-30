#include<vector>
#include<unordered_set>
#include<queue>
#include<unordered_map>
#include<iostream>
#include<algorithm>
#include<xutility>
#include<stack>

using namespace std;

class Twitter 
{
public:
    vector<unordered_set<int>> followers_sets {500, unordered_set<int>()};

    int twit_recency_ctr = 0;
    unordered_map<int, int> recency_id;

    vector<priority_queue<int, vector<int>, greater<int>>> feeds;
    
    Twitter() 
    {
        for(int i = 0 ; i < 500 ; i++)
        {
            followers_sets[i].insert(i);
        }
    }
    
    void postTweet(int userId, int tweetId)
    {
        recency_id[twit_recency_ctr] = tweetId;

        for(auto& user : followers_sets[userId])
        {
            feeds[user].push(twit_recency_ctr);
            if(feeds[user].size() > 10)
            {
                feeds[user].pop();
            }
        }

        twit_recency_ctr++;
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        vector<int> return_value;

        while (!feeds[userId].empty())
        {
            return_value.push_back(feeds[userId].top());
            feeds[userId].pop();
        }

        for(auto& twit : return_value)
        {
            feeds[userId].push(twit);
            twit = recency_id[twit];
        }
    
        return return_value;
    }
    
    void follow(int followerId, int followeeId) 
    {
        followers_sets[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        auto it = followers_sets[followeeId].find(followerId);
        followers_sets[followeeId].erase(followerId);
    }
};

int main()
{
    Twitter twitter {};

    twitter.postTweet(1, 5);

    cout<<"userId: "<<1<<" : ";
    for(auto& follower : twitter.followers_sets[1])
    {
        cout<<follower<<", ";
    }
    cout<<"\n";

    auto feed = twitter.getNewsFeed(1);    
    for(auto& f : feed)
    {
        cout<<" "<<f<<endl;
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

template <typename K, typename V>
bool IsSupersetEqual(unordered_map<K, V>& map1, unordered_map<K, V>& map2)
{
    for(const auto& [key, val] : map1)
    {
        if(!map2.contains[key]) return false;
        if(map1[key] != map2[key]) return false;
    }
    return true;
}

int main()
{
    vector<string> words
    {
        "ball",
        "area",
        "lead",
        "lady"
    };

    vector<unordered_map<char, int>> signatures (words.size());
    unordered_map<string, unordered_map<char, int>> word_signatures;

    for(auto& word : words)
    {
        for(auto& c : word)
        {
            word_signatures[word][c]++;
        }
    }

    for(int i = 0 ; i < words[0].length() ; i++)
    {
        for(auto& word : words)
        {
            signatures[i][word[i]]++;
        }
    }
    
    //for(auto& sig : signatures)
    //{
    //    for(const auto& [key, value] : sig)
    //    {
    //        cout<<"key: "<<key<<" value: "<<value<<"\n";
    //    }
    //    cout<<"\n";
    //}
    //
    //for(auto& word_sig : word_signatures)
    //{
    //    for(const auto& [key, value] : word_sig.second)
    //    {
    //        cout<<"key: "<<key<<" value: "<<value<<"\n";
    //    }
    //    cout<<"\n";
    //}
}

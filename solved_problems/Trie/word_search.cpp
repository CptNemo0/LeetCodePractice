#include "Trie.cpp"

class Solution 
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        Trie trie;
        for(auto& word : words)
        {
            trie.insert(word);
        }

        
    }
};
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>

using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    bool is_end;
};

class Trie
{
public:

    TrieNode* root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string& word)
    {
        auto current = root;
        for(auto& c : word)
        {
            if(!current->children.contains(c))
            {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->is_end = true;
    }

    bool search(string& word)
    {
        auto current = root;
        for(auto& c : word)
        {
            if(!current->children.contains(c)) return false;
            current = current->children[c];
        }
        return current->is_end;
    }

    bool startsWith(string& prefix)
    {
        auto current = root;
        for(auto& c : prefix)
        {
            if(!current->children.contains(c)) return false;
            current = current->children[c];
        }
        return true;
    }

    vector<string> getPrefixes(string& prefix)
    {
        if(prefix == "") return {};
        auto current = root;
        for(auto& c : prefix)
        {
            if(!current->children.contains(c)) return {};
            current = current->children[c];
        }

        queue<pair<TrieNode*, string>> q;
        q.push({current, prefix});

        vector<string> return_value;

        while(!q.empty() && return_value.size() < 1000)
        {
            const auto [node, str] = q.front();
            q.pop();
            if(!node) continue;

            if(node->is_end) return_value.push_back(str);

            for(const auto& [c, n] : node->children)
            {
                q.push({n, str + c});
            }
        }
        return return_value;
    }
};


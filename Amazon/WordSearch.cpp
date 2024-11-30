#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<iostream>

using namespace std;

class Solution 
{
public:
    vector<pair<int, int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    unordered_map<char, unordered_map<int, char>> next_of;
    bool visited[6][6];

    bool dfs(int x, int y, int letter_idx, string& word, vector<vector<char>>& board)
    {
        if(letter_idx == word.length() - 1) return true;

        const static auto not_in_bounds = [&board](int x, int y)
        {
            return !((x >= 0 && x < board[0].size()) && (y >= 0 && y < board.size()));
        };

        auto next = next_of[board[y][x]][letter_idx];
        
        visited[y][x] = true;

        for(auto& direction : directions)
        {
            int xx = x + direction.first;
            int yy = y + direction.second;

            if(not_in_bounds(xx, yy)) continue;
            if(visited[yy][xx])       continue;
            if(board[yy][xx] != next) continue;

            if(dfs(xx, yy, letter_idx + 1, word, board))
            {
                visited[y][x] = false;
                return true;
            }
        }

        visited[y][x] = false;
        return false; 
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        for(int i = 0 ; i < 6 ; i++)
        {
            for(int j = 0 ; j < 6; j++)
            {
                visited[i][j] = false;
            }
        }

        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < word.length() - 1 ; i++)
        {
            next_of[word[i]].insert({i, word[i + 1]});
        }
   
        for(int y = 0; y < m ; y++)
        {
            for(int x = 0; x < n; x++)
            {
                if(board[y][x] == word[0])
                {
                    if(dfs(x, y, 0, word, board)) return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution s {};

    vector<vector<char>> v {{'A','B','C','E'} ,{'S','F','E','S'} ,{'A','D','E','E'}};
    

    cout<<s.exist(v, "ABCESEEEFS")<<endl;
    return 0;
}
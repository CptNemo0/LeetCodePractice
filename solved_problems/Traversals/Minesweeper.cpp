#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Minesweeper
{
public:
  const int BOMB = 9;
  const int EMPTY = 0;
  vector<vector<int>> board;
  vector<vector<bool>> visited;
  int width;
  int height;
  int nob;

  const vector<pair<int, int>> directions 
  {
    {-1, -1}, {0, -1}, {1, -1},
    {-1,  0},          {1,  0},
    {-1,  1}, {0,  1}, {1,  1}
  };
  
  void Resize()
  {
    board = vector<vector<int>>(height, vector<int>(width, EMPTY));
    visited = vector<vector<bool>>(height, vector<bool>(width, false));
  }

  bool InBounds(int x, int y)
  {
    return (x > -1 && x < width) && (y > -1 && y < height);
  }

  void DistributeBombs()
  {
     srand(time(NULL));
     int ctr = 0;
     while(ctr != nob)
     {
       int x = rand() % width;
       int y = rand() % height;
       if(board[y][x] == BOMB) continue;
       board[y][x] = BOMB;
       ctr++;
       for(const auto& [dx, dy] : directions)
       {
         if(!InBounds(x + dx, y + dy)) continue;
         if(board[y + dy][x + dx] == BOMB) continue;
         board[y + dy][x + dx]++;
       }
     }
  }

  Minesweeper(int w, int h, int n)
  {
    width = w;
    height = h;
    nob = n;
    Resize();
    DistributeBombs();
  }

  int Reveal(int x, int y)
  {
    if(!InBounds(x, y)) return -1;
    if(visited[y][x]) return -1;
    if(board[y][x] == BOMB) return BOMB;
    
    visited[y][x] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    
    while(!q.empty())
    {
      const auto [ix, iy] = q.front();
      q.pop();
      
      if(board[iy][ix]) continue;
      
      for(const auto& [dx, dy] : directions)
      {
        if(!InBounds(ix + dx, iy + dy)) continue;
        if(visited[iy + dy][ix + dx]) continue;
        visited[iy + dy][ix + dx] = true;
        q.push({ix + dx, iy + dy});
      }    
    }
    return 0;
  }

  void Print()
  {
    for(int x = 0 ; x <= width ; x++)
    {
        if(x == 0) 
        {
            cout<<"X"<<"  ";
        }
        else
        {
            cout<<x - 1<<"  ";
        }   
    }
    cout<<"\n";
    for(int x = 0 ; x <= width ; x++)
    {
        if(x == 0) 
        {
            cout<<"Y"<<"  ";
        }
        else
        {
            cout<<"---";
        }   
    }
    cout<<"\n";
    for(int y = 0 ; y < height; y++)
    {
        cout<<y<<"| ";
        for(int x = 0 ; x < width ; x++)
        {
            //cout<<board[y][x]<<"  ";
            if(visited[y][x])
            {
                cout<<board[y][x]<<"  ";
            }
            else
            {
                cout<<char(254)<<"  ";
            }
        }
        cout<<"\n";
    }
  }

};

int main()
{
    Minesweeper game {10, 10, 1};

    while(true)
    {
        game.Print();
        int x = -1;
        int y = -1;
        cout<<"Input position of a field to be revealed: \n";
        cout<<"Input x: ";
        cin >> x;
        cout<<"\nInput y: ";
        cin >> y;
        cout<<"\n";
        int result = game.Reveal(x, y);
        system("CLS");
        if(result == 9) break;
    }
}
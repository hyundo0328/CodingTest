#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};

  char board[102][102];
  int vis[102][102];

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  int count = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(vis[i][j]) continue;
      count++;

      queue<pair<int,int> > Q;
      vis[i][j] = 1; 
      Q.push({i,j});

      while (!Q.empty()) {
        auto cur = Q.front(); 
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];

          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;

          vis[nx][ny] = 1;
          Q.push({ nx,ny });
        }
      }
    }
  }
  cout << count << " ";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if(board[i][j] == 'R' || board[i][j] == 'G'){
        board[i][j] = 'G';
      } else {
        board[i][j] = 'B';
      }
      vis[i][j] = 0;
    }
  }

  count = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(vis[i][j]) continue;
      count++;

      queue<pair<int,int> > Q;
      vis[i][j] = 1; 
      Q.push({i,j});

      while (!Q.empty()) {
        auto cur = Q.front(); 
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];

          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;

          vis[nx][ny] = 1;
          Q.push({ nx,ny });
        }
      }
    }
  }
  cout << count << " ";
}
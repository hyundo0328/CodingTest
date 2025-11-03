#include <bits/stdc++.h>
using namespace std;

char board[101][101];
int vis[101][101];

int n;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; 

void bfs(int i, int j) {
  queue<pair<int, int>> q;
  q.push({i, j});
  vis[i][j] = true;
  
  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(int dir=0; dir<4; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;

      vis[nx][ny] = 1;
      q.push({ nx,ny });
    }
  }
}

int area(){
  int count = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(vis[i][j]) continue;

      count++;
      bfs(i, j);
    }
  }

  return count;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
  int not_g = area();

  for(int i = 0; i < n; i++) fill(vis[i], vis[i]+n, false);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 'G') board[i][j] = 'R';
    }
  }

  int is_g = area();
  cout << not_g << " " << is_g;
  
  return 0;
}
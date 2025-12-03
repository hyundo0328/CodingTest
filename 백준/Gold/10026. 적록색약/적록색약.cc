#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char board[102][102];
bool vis[102][102];
int n;

void clear(){
  for(int i=0; i<n; i++) fill(vis[i], vis[i]+n, false);
}

void bfs(int x, int y){
  queue<pair<int, int>> q;
  q.push({x, y});

  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(int dir=0; dir<4; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
      if(board[x][y] != board[nx][ny] || vis[nx][ny]) continue;

      vis[nx][ny] = true;
      q.push({nx, ny});
    }
  }
}

int area(){
  int cnt = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(vis[i][j]) continue;

      cnt++;
      vis[i][j] = true;
      bfs(i, j);
    }
  }

  return cnt;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> board[i][j];
    }
  }  

  // 적녹색약 아닌 사람
  clear();
  cout << area() << " ";

  // 적녹색약인 사람
  clear();
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(board[i][j] == 'G') board[i][j] = 'R';
    }
  }
  cout << area();

}
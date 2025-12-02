#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[52][52];
bool vis[52][52];
int n, m, k;
int cnt = 0;
queue<pair<int, int>> q;

int bfs(){
  int width = 0;
  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(int dir=0; dir<4; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if(board[nx][ny] == 0 || vis[nx][ny]) continue;

      width++;
      vis[nx][ny] = true;
      q.push({nx, ny});
    }
  }

  return width;
}

void area(){
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(board[i][j] == 0 || vis[i][j]) continue;
      
      cnt++;
      board[i][j] = true;
      q.push({i, j});

      int width = bfs();
    }
  }

  cout << cnt << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    cin >> n >> m >> k;

    // 초기화
    cnt = 0; q = queue<pair<int, int>>();
    for(int i=0; i<n; i++){
      fill(board[i], board[i]+m, 0);
      fill(vis[i], vis[i]+m, false);
    }

    while(k--){
      int x, y;
      cin >> x >> y;

      board[x][y] = 1;
    }

    area();
  }
}
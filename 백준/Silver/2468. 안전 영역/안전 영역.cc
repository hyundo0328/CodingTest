#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[102][102];
bool vis[102][102];
int n, mx = 0, maxH = 0;

void bfs(queue<pair<int,int>>& q, int h){
  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(int dir=0; dir<4; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
      if(board[nx][ny] <= h || vis[nx][ny]) continue;
      
      vis[nx][ny] = true;
      q.push({nx, ny});
    }
  }
}

int area(int h){
  int cnt = 0;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(board[i][j] <= h || vis[i][j]) continue;

      cnt++;
      queue<pair<int,int>> q;
      q.push({i,j});

      bfs(q, h);
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
      maxH = max(maxH, board[i][j]);
    }
  }

  for(int h=0; h<maxH; h++){
    memset(vis, false, sizeof(vis)); // 방문 데이터 초기화

    int cnt = area(h);
    mx = max(mx, cnt);
  }

  cout << mx;
}
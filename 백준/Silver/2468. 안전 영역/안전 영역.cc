#include <bits/stdc++.h>
using namespace std;

int n, max_area, height;
int board[102][102];
bool vis[102][102];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int i, int j, int limit){
  queue<pair<int,int>> q;
  q.push({i,j});
  vis[i][j] = true;

  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(int dir=0;dir<4;dir++){
      int nx = dx[dir] + cur.first;
      int ny = dy[dir] + cur.second;

      if(nx < 0 || ny < 0 || nx > n || ny > n) continue;
      if(vis[nx][ny] || board[nx][ny] < limit) continue;

      vis[nx][ny] = true;
      q.push({nx, ny});
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin >> board[i][j];
      height = max(height, board[i][j]);
    }
  }

  for(int h=1; h<=height; h++){
    for(int i=1;i<=n;i++){
      fill(vis[i]+1, vis[i]+n+1, false);
    }
    
    int area = 0;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(vis[i][j] || board[i][j] < h) continue;

        bfs(i,j,h);
        area++;
      }
    }

    max_area = max(max_area, area);
  }

  cout << max_area;
}
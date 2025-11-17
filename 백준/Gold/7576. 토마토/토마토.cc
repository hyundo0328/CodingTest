#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[1002][1002];
int dis[1002][1002];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m, n;
  cin >> m >> n;

  queue<pair<int,int>> q;
  for(int i=0; i<n; i++){
    fill(dis[i], dis[i]+m, -1);
    for(int j=0; j<m; j++){
      cin >> board[i][j];
      if(board[i][j] == 1) {
        dis[i][j] = 0;
        q.push({i,j});
      }
    }
  }

  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(int i=0; i<4; i++){
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if(board[nx][ny] == -1) continue;
      if(dis[nx][ny] != -1 || dis[nx][ny] > dis[cur.first][cur.second] + 1) continue;

      q.push({nx, ny});
      dis[nx][ny] = dis[cur.first][cur.second]+1;
    }
  }

  // for(int i=0; i<n; i++){
  //   for(int j=0; j<m; j++){
  //     cout << dis[i][j] << " ";
  //   }
  //   cout << '\n';
  // }

  int mx_day = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(board[i][j] == 0 && dis[i][j] == -1){
        cout << -1;
        return 0;
      }

      mx_day = max(mx_day, dis[i][j]);
    }
  }

  cout << mx_day;

  return 0;
}
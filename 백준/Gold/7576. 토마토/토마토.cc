#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[1002][1002];
int dis[1002][1002];

int n, m;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  queue<pair<int,int>> Q;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> board[i][j];
      if(board[i][j] == 1)
        Q.push({i,j});
      if(board[i][j] == 0)
        dis[i][j] = -1;
    }
  }
  
  while(!Q.empty()){
    auto cur = Q.front();
    Q.pop();    

    for(int i=0;i<4;i++){
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
        continue;
      }
      if(dis[nx][ny] >= 0) {
        continue;
      }

      dis[nx][ny] = dis[cur.first][cur.second] + 1;
      Q.push({nx,ny});
    }
  }

  int day = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(dis[i][j] == -1){
        cout << -1;
        return 0;
      }
      day = max(day, dis[i][j]);
    }
  }
  cout << day;

  return 0;
}
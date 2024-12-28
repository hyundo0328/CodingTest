#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];
int dis[1001][1001];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m, n;
  cin >> m >> n;

  queue<pair<int,int>> Q;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> board[i][j];
      if(board[i][j] == 1){
        Q.push({i,j});
        dis[i][j] = 0;
      }
      if(board[i][j] == 0)
        dis[i][j] = -1;
    }
  }

  while(!Q.empty()){
    pair<int,int> cur = Q.front(); Q.pop();
    for(int k=0;k<4;k++){
      int nextX = cur.first + dx[k];
      int nextY = cur.second + dy[k];

      if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= m) continue;
      if(dis[nextX][nextY] >= 0) {
        continue;
      }

      dis[nextX][nextY] = dis[cur.first][cur.second]+1;
      Q.push({nextX, nextY});
    }
  }

  int max_day = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(dis[i][j] == -1){
        cout << -1;
        return 0;
      }
      max_day = max(max_day, dis[i][j]);
    }
  }
  cout << max_day;
}
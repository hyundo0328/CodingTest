#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};
  int board[102][102] = {0,};
  int dis[102][102] = {0,};
  
  int n, m;
  cin >> n >> m;

  for(int i=0;i<n;i++){
    string tmp;
    cin >> tmp;
    for(int j=0;j<m;j++){
      board[i][j] = tmp[j] - '0';
    }
  }

  for(int i = 0; i < n; i++) fill(dis[i],dis[i]+m,-1);

  int distance = 0;
  queue<pair<int,int>> Q;

  dis[0][0] = distance;
  Q.push({0,0});

  while(!Q.empty()){
    pair<int, int> cur = Q.front();
    Q.pop();    

    distance++;
    for(int i=0;i<4;i++){
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
        continue;
      }
      if(dis[nx][ny] != -1 || board[nx][ny] == 0) {
        continue;
      }

      dis[nx][ny] = dis[cur.first][cur.second] + 1;
      Q.push({nx,ny});
    }
  }

  cout << dis[n-1][m-1] + 1;

  return 0;
}
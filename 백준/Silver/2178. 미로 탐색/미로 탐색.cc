#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[102][102];
int dis[102][102];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i=0; i<n; i++){
    string str; cin >> str;
    for(int j=0; j<m; j++) board[i][j] = str.at(j) - '0';
  }

  dis[0][0] = 1;
  queue<pair<int, int>> q;
  q.push({0,0});

  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(int dir=0; dir<4; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if(board[nx][ny] == 0 || dis[nx][ny] != 0) continue;
      if(dis[nx][ny] >= dis[cur.first][cur.second] + 1) continue;

      dis[nx][ny] = dis[cur.first][cur.second] + 1;
      q.push({nx, ny});
    }
  }

  cout << dis[n-1][m-1];
}
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[1002][1002];
int dis[1002][1002][2];
int n, m;

int bfs(){
  queue<tuple<int, int, int>> q;
  q.push({0,0,0});

  while(!q.empty()){
    int x, y, broken;
    tie(x,y,broken) = q.front(); q.pop();

    if(x == n-1 && y == m-1) return dis[x][y][broken];

    for(int dir=0; dir<4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      
      if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if(board[nx][ny] == 0 && dis[nx][ny][broken] == 0){
        dis[nx][ny][broken] = dis[x][y][broken] + 1;
        q.push({nx, ny, broken});
      }

      if(!broken && board[nx][ny] == 1 && dis[nx][ny][broken] == 0){
        dis[nx][ny][1] = dis[x][y][broken] + 1;
        q.push({nx, ny, true});
      }
    }
  }

  return -1;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i=0; i<n; i++){
    string tmp; cin >> tmp;
    for(int j=0; j<m; j++){
      board[i][j] = tmp.at(j) - '0';
    }
  }

  dis[0][0][0] = 1;
  cout << bfs();
}
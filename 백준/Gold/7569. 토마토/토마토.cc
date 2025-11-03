#include <bits/stdc++.h>
using namespace std;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int board[102][102][102];
int dis[102][102][102];

int m, n, h;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n >> h;

  queue<pair<pair<int, int>, int>> q;
  memset(dis, -1, sizeof(dis));

  for(int k=1; k<=h; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
        cin >> board[i][j][k];

        if(board[i][j][k] == 1) {
          q.push({{i,j}, k});
          dis[i][j][k] = 0;
        }
      }
    }
  }

  int day = 0;
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    int x = cur.first.first;
    int y = cur.first.second;
    int z = cur.second;
    // cout << "시작 좌표 x, y, z: " << x << " " << y << " " << z << " " << dis[x][y][z] << '\n';

    for(int dir = 0; dir < 6; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      int nz = z + dz[dir];

      /* 예외 */
      if(nx < 1 || nx > n || ny < 1 || ny > m || nz < 1 || nz > h) continue; // 상자 벗어남
      if(dis[nx][ny][nz] > -1 || board[nx][ny][nz] != 0) continue; // 이미 체크 or 익음
      
      dis[nx][ny][nz] = dis[x][y][z] + 1;
      // cout << "x, y, z: " << nx << " " << ny << " " << nz << " " << dis[nx][ny][nz] << '\n';
      day = max(day, dis[nx][ny][nz]);
      q.push({{nx,ny},nz});
    }
  }

  for(int k=1;k<=h;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(board[i][j][k] == 0 && dis[i][j][k] == -1) {
          cout << -1;
          return 0;
        }
      }
    }
  }

  cout << day;
  return 0;
}
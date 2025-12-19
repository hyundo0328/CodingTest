#include <bits/stdc++.h>
using namespace std;

int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int board[102][102][102];
int dis[102][102][102];
int m, n, h;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n >> h;

  memset(dis, -1, sizeof(dis));
  queue<tuple<int,int,int>> q;

  // board 등록, 익은 토마토 큐에 저장
  for(int height = 0; height < h; height++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> board[i][j][height];

        if(board[i][j][height] == 1){
          dis[i][j][height] = 0;
          q.push({i,j,height});
        }
      }
    }
  }

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    int curX, curY, curZ;
    tie(curX, curY, curZ) = cur;

    for(int dir=0; dir<6; dir++){
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      int nz = curZ + dz[dir];

      if(nx < 0 || ny < 0 || nz < 0 || nx >=n || ny >= m || nz >= h) continue;
      if(board[nx][ny][nz] == -1 || dis[nx][ny][nz] != -1) continue;

      dis[nx][ny][nz] = dis[curX][curY][curZ] + 1;
      q.push({nx,ny,nz});
    }
  }

  int mx = 0;
  for(int height=0; height<h; height++){
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(board[i][j][height] != -1 && dis[i][j][height] == -1){
          cout << -1;
          return 0;
        }
        mx = max(mx, dis[i][j][height]);
      }
    }
  }

  cout << mx;
}
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char board[1002][1002];
int disJ[1002][1002];
int disF[1002][1002];
int r, c;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c;
  queue<pair<int, int>> qj;
  queue<pair<int, int>> qf;

  for(int i=0; i<r; i++){
    cin >> board[i];
    fill(disJ[i], disJ[i]+c, -1);
    fill(disF[i], disF[i]+c, -1);
    for(int j=0; j<c; j++){
      if(board[i][j] == 'J'){
        disJ[i][j] = 0;
        qj.push({i,j});
      }

      if(board[i][j] == 'F'){
        disF[i][j] = 0;
        qf.push({i,j});
      }
    }
  }

  while(!qf.empty()){
    auto cur = qf.front(); qf.pop();

    for(int dir=0; dir<4; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
      if(board[nx][ny] == '#' || disF[nx][ny] >= 0) continue;

      disF[nx][ny] = disF[cur.first][cur.second] + 1;
      qf.push({nx,ny});
    }
  }

  while(!qj.empty()){
    auto cur = qj.front(); qj.pop();

    for(int dir=0; dir<4; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if(nx < 0 || ny < 0 || nx >= r || ny >= c){
        cout << disJ[cur.first][cur.second] + 1;
        return 0;
      }
      if(board[nx][ny] == '#' || disJ[nx][ny] >= 0) continue;
      if(disF[nx][ny] != -1 && disJ[cur.first][cur.second] + 1 >= disF[nx][ny]) continue;

      disJ[nx][ny] = disJ[cur.first][cur.second] + 1;
      qj.push({nx,ny});
    }
  }

  cout << "IMPOSSIBLE";
}
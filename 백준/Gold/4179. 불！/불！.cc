#include <bits/stdc++.h>
using namespace std;

string board[1001];
int disJ[1001][1001];
int disF[1001][1001];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m, n;
  cin >> n >> m;

  queue<pair<int,int>> Q_J;
  queue<pair<int,int>> Q_F;

  for(int i = 0; i < n; i++){
    fill(disJ[i], disJ[i]+m, -1);
    fill(disF[i], disF[i]+m, -1);    
  }

  for(int i=0;i<n;i++){
    cin >> board[i];
    for(int j=0;j<m;j++){
      if(board[i][j] == 'J'){
        disJ[i][j] = 0;
        Q_J.push({i,j});
      } else if (board[i][j] == 'F'){
        disF[i][j] = 0;
        Q_F.push({i,j});
      }
    }
  }

  while(!Q_F.empty()){
    pair<int,int> cur = Q_F.front(); Q_F.pop();
    for(int k=0;k<4;k++){
      int nextX = cur.first + dx[k];
      int nextY = cur.second + dy[k];

      if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= m) continue;
      if(disF[nextX][nextY] >= 0) continue;
      if(board[nextX][nextY] == '#') continue;

      disF[nextX][nextY] = disF[cur.first][cur.second]+1;
      Q_F.push({nextX, nextY});
    }
  }

  while(!Q_J.empty()){
    pair<int,int> cur = Q_J.front(); Q_J.pop();
    for(int k=0;k<4;k++){
      int nextX = cur.first + dx[k];
      int nextY = cur.second + dy[k];

      if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= m) {
        cout << disJ[cur.first][cur.second]+1;
        return 0;
      }
      if(disJ[cur.first][cur.second]+1 >= disF[nextX][nextY] && disF[nextX][nextY] != -1) continue;
      if(disJ[nextX][nextY] >= 0) continue;
      if(board[nextX][nextY] == '#') continue;

      disJ[nextX][nextY] = disJ[cur.first][cur.second]+1;
      Q_J.push({nextX, nextY});
    }
  }

  cout << "IMPOSSIBLE";
}
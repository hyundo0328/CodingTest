#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char board[1002][1002];
int disF[1002][1002];
int disS[1002][1002];
int n, m, t;
bool flag;
queue<pair<int,int>> qf;
queue<pair<int,int>> qs;

void init(){
  for(int i=0; i<1002; i++){
    fill(disF[i], disF[i] + 1002, -1);
    fill(disS[i], disS[i] + 1002, -1);
  }

  flag = false;
  qf = {}; qs = {};
}

void input(){
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> board[i][j];
      if(board[i][j] == '@'){
        disS[i][j] = 0;
        qs.push({i,j});
      }

      if(board[i][j] == '*'){
        disF[i][j] = 0;
        qf.push({i,j});
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  
  while(t--){
    cin >> m >> n;

    init();
    input();

    // 불의 이동거리
    while(!qf.empty()){
      auto cur = qf.front(); qf.pop();

      for(int dir=0; dir<4; dir++){
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(board[nx][ny] == '#' || disF[nx][ny] != -1) continue;

        disF[nx][ny] = disF[cur.first][cur.second] + 1;
        qf.push({nx,ny});
      }
    }

    // 상근 이동거리
    while(!qs.empty() && !flag){
      auto cur = qs.front(); qs.pop();

      for(int dir=0; dir<4; dir++){
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m){
          flag = true;
          cout << disS[cur.first][cur.second] + 1 << '\n';
          break;
        }
        if(board[nx][ny] == '#' || board[nx][ny] == '*' || disS[nx][ny] != -1) continue;
        if(disF[nx][ny] != -1 && disF[nx][ny] <= disS[cur.first][cur.second] + 1) continue;

        disS[nx][ny] = disS[cur.first][cur.second] + 1;
        qs.push({nx,ny});
      }
    }

    if(!flag) cout << "IMPOSSIBLE\n";
  }
}
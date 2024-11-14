#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

string board[1002];
int disJihun[1002][1002];
int disFire[1002][1002];

int r, c;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c;
  queue<pair<int,int>> Jihun;
  queue<pair<int,int>> Fire;

  for(int i = 0; i < r; i++){
    fill(disJihun[i], disJihun[i]+c, -1);
    fill(disFire[i], disFire[i]+c, -1);    
  }

  for(int i=0;i<r;i++){
    cin >> board[i];
    for(int j=0;j<c;j++){
      if(board[i][j] == 'J'){
        Jihun.push({i,j});
        disJihun[i][j] = 0;
      }
      if(board[i][j] == 'F'){
        Fire.push({i,j});
        disFire[i][j] = 0;
      }
    }
  }

  while(!Fire.empty()){
    auto cur = Fire.front();
    Fire.pop();    

    for(int i=0;i<4;i++){
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if(nx < 0 || ny < 0 || nx >= r || ny >= c) {
        continue;
      }
      if(disFire[nx][ny] >= 0 || board[nx][ny] == '#') {
        continue;
      }

      disFire[nx][ny] = disFire[cur.first][cur.second] + 1;
      Fire.push({nx,ny});
    }
  }
  
  while(!Jihun.empty()){
    auto cur = Jihun.front();
    Jihun.pop();    

    for(int i=0;i<4;i++){
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if(nx < 0 || ny < 0 || nx >= r || ny >= c) {
        cout << disJihun[cur.first][cur.second]+1; 
        return 0;
      }
      if(disJihun[cur.first][cur.second]+1 >= disFire[nx][ny] && disFire[nx][ny] != -1) {
        continue;
      }
      if(disJihun[nx][ny] >= 0 || board[nx][ny] == '#') {
        continue;
      }

      
      disJihun[nx][ny] = disJihun[cur.first][cur.second] + 1;
      Jihun.push({nx,ny});
    }
  }

  cout << "IMPOSSIBLE";
}
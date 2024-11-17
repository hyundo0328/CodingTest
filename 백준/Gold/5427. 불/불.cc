#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bX, bY;
int board[1002][1002];
int visF[1002][1002];
int visS[1002][1002];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int c;
  cin >> c;

  while(c-- > 0){
    bool escape = false;
    cin >> bY >> bX;

    queue<pair<int,int>> Sanguen;
    queue<pair<int,int>> Fire;

    for (int i = 0; i < bX; i++) {
      fill(visF[i], visF[i] + bY, 0);
      fill(visS[i], visS[i] + bY, 0);
    }
    for (int i = 0; i < bX; i++){
      for (int j = 0; j < bY; j++) {
        char c;
        cin >> c;
        if (c == '#') board[i][j] = -1;
        else {
          if (c == '@') {
            Sanguen.push({i, j});
            visS[i][j] = 1;
          } 
          else if (c == '*') {
            Fire.push({i, j});
            visF[i][j] = 1;
          }
          board[i][j] = 0;
        }
      }
    }


    while(!Fire.empty()){
      auto cur = Fire.front();
      Fire.pop();

      for(int i=0;i<4;i++){
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];

        if(nx < 0 || nx >= bX || ny < 0 || ny >= bY) {
          continue;
        }
        if(visF[nx][ny] > 0 || board[nx][ny] == -1) {
          continue;
        }

        visF[nx][ny] = visF[cur.first][cur.second] + 1;
        Fire.push({nx,ny});
      }
    }

    while ((!Sanguen.empty()) && (!escape)) {
      auto cur = Sanguen.front();
      Sanguen.pop();
      for (int k = 0; k < 4; k++) {
        int nx = cur.first + dx[k];
        int ny = cur.second + dy[k];
        if (nx < 0 || bX <= nx || ny < 0 || bY <= ny) {
          cout << visS[cur.first][cur.second] << '\n';
          escape = true;
          break;
        }
        if (board[nx][ny] == -1) continue;
        if (visS[nx][ny]) continue;
        if (visF[nx][ny] != 0 && visF[nx][ny] <= visS[cur.first][cur.second] + 1) continue;
        visS[nx][ny] = visS[cur.first][cur.second] + 1;
        Sanguen.push({nx, ny});
      }
    }
    if (!escape) cout << "IMPOSSIBLE\n";
  }

  return 0;
}
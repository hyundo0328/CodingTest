#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[102][102];
int vis[102][102];

int main() {
  int t;
  cin >> t;

  while(t-- > 0){
    int count = 0;
    int x, y;
    cin >> x >> y;

    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
          board[i][j] = 0;
          vis[i][j] = 0;
      }
    }

    for(int i = 0;i < x;i++){
      string tmp;
      cin >> tmp;
      for(int j = 0; j < y; j++){
        if(tmp[j] == '#'){
          board[i][j] = 1;
        } else {
          board[i][j] = 0;
        }
      }
    }

    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        if(board[i][j] == 0 || vis[i][j] == 1) continue;
        count++;
        queue<pair<int, int>> Q;

        Q.push({ i,j });
        vis[i][j] = 1;

        while(!Q.empty()){
          pair<int,int> cur = Q.front(); Q.pop();
          for(int k=0;k<4;k++){
            int nextX = cur.first + dx[k];
            int nextY = cur.second + dy[k];

            if(nextX < 0 || nextY < 0 || nextX >= x || nextY >= y) continue;
            if(board[nextX][nextY] == 0 || vis[nextX][nextY] == 1) continue;

            vis[nextX][nextY] = 1;
            Q.push({nextX, nextY});
          }
        }
      }
    }

    cout << count << '\n';
  }
  
  return 0;
}

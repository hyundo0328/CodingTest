#include <bits/stdc++.h>
using namespace std;

int t;
int n, m, k;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[52][52];
int vis[52][52];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t-- > 0){
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
      fill(board[i], board[i]+m, 0);
      fill(vis[i], vis[i]+m, 0);
    }

    // queue<pair<int,int>> Q;

    for(int i=0;i<k;i++){
      int x, y;
      cin >> x >> y;
      board[x][y] = 1;
    }

    int count = 0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(vis[i][j] == 1 || board[i][j] == 0) continue;
        
        queue<pair<int,int>> Q;
        vis[i][j] == 1;
        Q.push({i,j});
        count++;

        while(!Q.empty()){
          auto cur = Q.front();
          Q.pop();    

          for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
              continue;
            }
            if(vis[nx][ny] == 1 || board[nx][ny] == 0) {
              continue;
            }

            vis[nx][ny] = 1;
            Q.push({nx,ny});
          }
        }
      }
    }

    cout << count << '\n';
  }
}
#include <bits/stdc++.h>
using namespace std;

int board[502][502];
bool vis[502][502] = {false,};

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> board[i][j];
    }
  }

  int count = 0, width = 0, mx = 0;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(vis[i][j] == true || board[i][j] == 0) continue;

      count++;
      vis[i][j] = true;
      queue<pair<int, int>> Q;
      Q.push({i,j});

      width = 0;
      while(!Q.empty()){
        width++;
        auto cur = Q.front(); Q.pop();

        for(int dir=0;dir<4;dir++){
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];

          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
          if(vis[nx][ny] || board[nx][ny] == 0) continue; 

          vis[nx][ny] = true;
          Q.push({nx,ny});
        }
        
      }
      mx = max(mx, width); 
    }
  }
  cout << count << "\n" << mx;

}

#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};

  int n, m;
  cin >> n >> m;

  int board[502][502] = {0,};
  bool vis[502][502] = {false,};
  queue<pair<int,int> > Q;

  int count = 0;
  int width = 0;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> board[i][j];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){ 
      if(board[i][j] == 0 || vis[i][j]) continue; 
      count++; 

      queue<pair<int,int> > Q;
      vis[i][j] = true; 
      Q.push({i,j});
      int area = 0; 
      while(!Q.empty()){
        area++; 
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int dir = 0; dir < 4; dir++){ 
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];
          
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
          if(vis[nx][ny] || board[nx][ny] != 1) continue; 

          vis[nx][ny] = true; 
          Q.push({nx,ny});
        }
      }
      width = max(width, area); 
    }
  }
  cout << count << "\n" << width;

  return 0;
}

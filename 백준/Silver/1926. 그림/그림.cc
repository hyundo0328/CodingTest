#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int count = 0;
  int width = 0;

  int board[502][502];
  bool vis[502][502];
  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> board[i][j];
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(board[i][j] == 0 || vis[i][j]) continue;
      count++;

      queue<pair<int,int>> Q;
      vis[i][j] = true;
      Q.push({i,j});

      int area = 0;
      while(!Q.empty()){
        area++;
        pair<int,int> cur = Q.front(); Q.pop();
        for(int k=0;k<4;k++){
          int nextX = cur.first + dx[k];
          int nextY = cur.second + dy[k];

          if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= m) continue;
          if(board[nextX][nextY] == 0 || vis[nextX][nextY]) continue;

          vis[nextX][nextY] = true;
          Q.push({nextX, nextY});
        }
      }
      width = max(area, width);
    }
  }

  cout << count << '\n' << width;
}
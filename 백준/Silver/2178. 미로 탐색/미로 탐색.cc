#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int board[502][502];
  int dis[502][502];

  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};

  for(int i=0;i<n;i++){
    string tmp;
    cin >> tmp;
    for(int j=0;j<m;j++){
      board[i][j] = tmp[j] - '0';
    }
  }

  for(int i = 0; i < n; i++) fill(dis[i],dis[i]+m,-1);

  queue<pair<int,int>> Q;
  dis[0][0] = 1;
  Q.push({0,0});

  while(!Q.empty()){
    pair<int,int> cur = Q.front(); Q.pop();
    for(int k=0;k<4;k++){
      int nextX = cur.first + dx[k];
      int nextY = cur.second + dy[k];

      if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= m) continue;
      if(board[nextX][nextY] == 0 || dis[nextX][nextY] != -1) continue;

      dis[nextX][nextY] = dis[cur.first][cur.second]+1;
      Q.push({nextX, nextY});
    }
  }

  cout << dis[n-1][m-1];
}
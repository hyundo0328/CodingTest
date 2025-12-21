#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
string board[27];
bool vis[27][27];
int n, width = 1, cnt = 0;
vector<int> vec;
queue<pair<int,int>> q;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) cin >> board[i];

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(board[i][j] == '0' || vis[i][j]) continue;

      cnt++;
      vis[i][j] = true;
      q.push({i,j});

      while(!q.empty()){
        auto cur = q.front(); q.pop();

        for(int dir=0; dir<4; dir++){
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];

          if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
          if(board[nx][ny] == '0' || vis[nx][ny]) continue;
          
          width++;
          vis[nx][ny] = true;
          q.push({nx, ny});
        }
      }

      vec.push_back(width);
      width = 1;
    }
  }

  sort(vec.begin(), vec.end());
  cout << cnt << '\n';
  for(int wid:vec) cout << wid << '\n';
}
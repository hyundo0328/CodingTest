
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[27][27];
int vis[27][27];
int n;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0;i<n;i++){
    string tmp;
    cin >> tmp;
    for(int j=0;j<n;j++){
      board[i][j] = tmp[j]-'0';
    }
  }

  int count = 0;
  vector<int> ans;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 0 || vis[i][j] == 1) continue;

      queue<pair<int, int>> Q;
      Q.push({ i, j });
      vis[i][j] = 1;
      
      int width = 1;
      count++;

      while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];

          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (board[nx][ny] == 0 || vis[nx][ny] == 1) continue;

          Q.push({ nx, ny });
          vis[nx][ny] = 1;
          width++;
        }
      }
      ans.push_back(width);
    }
  }
  sort(ans.begin(), ans.end());

  cout << count << '\n';
  for (int i : ans)
    cout << i << '\n'; 

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[102][102];
int vis[102][102];
int m, n, k;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m, n, k;
  cin >> m >> n >> k;

  while(k-- > 0){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for(int i=b;i<d;i++){
      for(int j=a;j<c;j++){
        board[i][j] = 1;
      }
    }
  }

  int count = 0;
  vector<int> ans;
	
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 1 || vis[i][j] == 1)
        continue;
      queue<pair<int, int>> Q;
      vis[i][j] = 1;
      Q.push({ i, j });
      int width = 1;
      count++;
      while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];
          if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
          if (board[nx][ny] == 1 || vis[nx][ny] == 1)
            continue;
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
    cout << i << ' '; 

  return 0;
}
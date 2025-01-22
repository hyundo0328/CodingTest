#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int board[27][27];
bool vis[27][27];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    for(int j=0;j<n;j++){
      board[i][j] = s[j] - '0';
    }
  }

  int count = 0;
  vector<int> ans;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(board[i][j] == 0 || !!vis[i][j]) continue;

      queue<pair<int,int>> Q;
      Q.push({i,j});
      vis[i][j] = true;
      
      count++;
      int width = 1;

      while(!Q.empty()){
        auto cur = Q.front(); Q.pop();

        for(int dir=0; dir<4; dir++){
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];

          if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
          if(!!vis[nx][ny] || board[nx][ny] == 0) continue;

          Q.push({nx,ny});
          vis[nx][ny] = true;
          width++;
        }
      }

      ans.push_back(width);
    }
  }

  sort(ans.begin(), ans.end());

  cout << count << '\n';
  for(auto width:ans){
    cout << width << '\n';
  }
}
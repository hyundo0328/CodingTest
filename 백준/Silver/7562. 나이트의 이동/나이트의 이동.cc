#include <bits/stdc++.h>
using namespace std;

int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int board[302][302];
int dis[302][302];
int n, t;
queue<pair<int,int>> q;

void init(){
  q = queue<pair<int,int>>();
  memset(board, 0, sizeof(board));
  memset(dis, -1, sizeof(dis));
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--){
    init();

    cin >> n;
    int startX, startY, goalX, goalY;
    cin >> startX >> startY;
    cin >> goalX >> goalY;
    
    dis[startX][startY] = 0;
    q.push({startX, startY});
    while(!q.empty()){
      auto cur = q.front(); q.pop();

      for(int dir=0; dir<8; dir++){
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(dis[nx][ny] != -1 && dis[nx][ny] <= dis[cur.first][cur.second] + 1) continue;

        dis[nx][ny] = dis[cur.first][cur.second] + 1;
        q.push({nx, ny});
      }
    }

    cout << dis[goalX][goalY] << '\n';
  }
}
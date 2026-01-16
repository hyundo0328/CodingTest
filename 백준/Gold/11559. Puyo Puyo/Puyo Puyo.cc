#include <bits/stdc++.h>
using namespace std;

// 뿌요는 중력의 영향을 받아 아래에 바닥이나 다른 뿌요가 나올 때까지 아래로 떨어진다.
// 같은 색 뿌요가 4개 이상 상하좌우로 연결되면 연결된 뿌요들이 한꺼번에 없어진다. -> 1연쇄
// 뿌요들이 없어지고 나서 위에 다른 뿌요들이 있다면, 중력의 영향을 받아 아래로 떨어지게 된다.
// 아래로 떨어지고 나서 다시 같은 색의 뿌요들이 4개 이상 모이게 되면 터짐 -> 1연쇄 추가
// 터질 수 있는 뿌요가 여러 그룹이 있다면 동시에 터지고 여러 그룹이 터지더라도 한번의 연쇄가 추가된다.

int ans;
bool isPuyo;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char board[12][6];
bool vis[12][6];

void puyo(int x, int y){
  char color = board[x][y];
  vis[x][y] = true;

  queue<pair<int, int>> q;
  q.push({x, y});

  vector<pair<int,int>> vec;
  vec.push_back({x, y});

  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(int dir=0; dir<4; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if(nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
      if(board[nx][ny] == '.' || board[nx][ny] != color || vis[nx][ny]) continue;

      vis[nx][ny] = true;
      vec.push_back({nx, ny});
      q.push({nx, ny});
    }
  }
  
  if(vec.size() >= 4){
    isPuyo = true;

    for(auto v:vec) board[v.first][v.second] = '.';
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  // 뿌요 입력
  for(int i=11; i>=0; i--){
    string tmp; cin >> tmp;
    for(int j=0; j<6; j++) board[i][j] = tmp.at(j);
  }

  while(true){
    isPuyo = false;
    for(int i=0; i<12; i++){
      for(int j=0; j<6; j++){
        if(board[i][j] == '.' || vis[i][j]) continue;

        puyo(i, j);
      }
    }

    if(isPuyo) {
      ans++;
      memset(vis, false, sizeof(vis));
    } else break;

    for(int j=0; j<6; j++){
      for(int i=10; i>=0; i--){
        int tmp = i;
        while(tmp < 11 && board[tmp][j] == '.'){
          swap(board[tmp][j], board[tmp+1][j]);
          tmp++;
        }
      }
    }
  }

  cout << ans;
}
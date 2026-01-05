#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board1[9][9];
int board2[9][9];
int n, m, cnt;
vector<pair<int,int>> cctv;

void init(){
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      board2[i][j] = board1[i][j];
}

void check(int x, int y, int dir){
  dir %= 4;
  while(true){
    x += dx[dir]; y += dy[dir];
    
    // 벽을 만나거나 맵의 끝에 가면 종료
    if(x < 0 || y < 0 || x >= n || y >= m) return;
    if(board2[x][y] == 6) return; 
    
    if(board2[x][y] != 0) continue; // cctv가 있으면 건너뛰기
    board2[x][y] = 7;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> board1[i][j];

      if(board1[i][j] != 0 && board1[i][j] != 6) cctv.push_back({i,j});
      if(board1[i][j] == 0) cnt++;
    }
  }

  for(int t=0; t<(1<<(2*cctv.size())); t++){
    int num = t;
    init();

    for(int tv=0; tv<cctv.size(); tv++){
      int dir = num % 4; num /= 4;

      int x = cctv.at(tv).first;
      int y = cctv.at(tv).second;

      if(board1[x][y] == 1){ // 1번 CCTV
        check(x, y, dir);
      } else if (board1[x][y] == 2){ // 2번 CCTV
        check(x, y, dir);
        check(x, y, dir+2);
      } else if (board1[x][y] == 3){ // 3번 CCTV
        check(x, y, dir);
        check(x, y, dir+1);
      } else if (board1[x][y] == 4){ // 4번 CCTV
        check(x, y, dir);
        check(x, y, dir+1);
        check(x, y, dir+2);
      } else if (board1[x][y] == 5){ // 5번 CCTV
        check(x, y, dir);
        check(x, y, dir+1);
        check(x, y, dir+2);
        check(x, y, dir+3);
      }
    }

    int val = 0;
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        if(board2[i][j] == 0) val++;
    
    cnt = min(cnt, val);
  }
  
  cout << cnt;
}
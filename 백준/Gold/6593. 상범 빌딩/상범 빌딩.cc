#include <bits/stdc++.h>
using namespace std;

int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
char building[32][32][32]; // [층][행][열]
int times[32][32][32];
int n, m, h;
int goalX, goalY, goalZ;
bool isEscape;
queue<tuple<int,int,int>> q;

void init(){
  memset(building, ' ', sizeof(building));
  memset(times, -1, sizeof(times));
  q = queue<tuple<int,int,int>>();
  goalX = -1; goalY = -1; goalZ = -1;
  isEscape = false;
}

void input(int h, int n, int m){
  for(int k=0; k<h; k++){
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin >> building[k][i][j];

        if(building[k][i][j] == 'S'){
          q.push({k, i, j});
          times[k][i][j] = 0;
        }
        if(building[k][i][j] == 'E'){
          goalX = i;
          goalY = j;
          goalZ = k;
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(true){
    cin >> h >> n >> m;
    if(h == 0 && n == 0 && m == 0) return 0;

    init();
    input(h, n, m);

    while(!isEscape && !q.empty()){
      auto cur = q.front(); q.pop();
      int curX, curY, curZ;
      tie(curZ, curX, curY) = cur;

      for(int dir=0; dir<6; dir++){
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        int nz = curZ + dz[dir];

        if(nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
        if(building[nz][nx][ny] == '#' || times[nz][nx][ny] != -1) continue;

        times[nz][nx][ny] = times[curZ][curX][curY] + 1;

        if(building[nz][nx][ny] == 'E'){
          isEscape = true;
          break;
        }

        q.push({nz, nx, ny});
      }
    }

    if(isEscape) cout << "Escaped in " << times[goalZ][goalX][goalY] << " minute(s).\n";
    else cout << "Trapped!\n";
  }
}
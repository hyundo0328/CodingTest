#include <bits/stdc++.h>
using namespace std;

int notebook[42][42];
int sticker[12][12];
int n, m, k;
int r, c;

void rotate(){
  int tmp[12][12];

  for(int i=0; i<r; i++)
    for(int j=0; j<c; j++)
      tmp[i][j] = sticker[i][j];
  
  for(int i=0; i<c; i++)
    for(int j=0; j<r; j++)
      sticker[i][j] = tmp[r-1-j][i];

  swap(r, c);
}

bool postable(int x, int y){
  // 붙일 수 있는지 체크
  for(int i=0; i<r; i++)
    for(int j=0; j<c; j++)
      if(sticker[i][j] == 1 && notebook[x+i][y+j] == 1) return false;

  // 붙이기
  for(int i=0; i<r; i++)
    for(int j=0; j<c; j++)
      if(sticker[i][j] == 1) notebook[x+i][y+j] = 1;

  return true;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  while(k--){
    cin >> r >> c;

    memset(sticker, 0, sizeof(sticker));

    for(int i=0; i<r; i++)
      for(int j=0; j<c; j++)
        cin >> sticker[i][j];

    for(int rot=0; rot<4; rot++){
      bool isPosted = false;
      for(int i=0; i<=n-r; i++){
        if(isPosted) break;
        for(int j=0; j<=m-c; j++){
          if(postable(i,j)){
            isPosted = true;
            break;
          }
        }
      }

      if(isPosted) break;
      rotate();
    }
  }

  int cnt = 0;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(notebook[i][j] == 1) cnt++;
  
  cout << cnt;
}
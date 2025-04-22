#include <bits/stdc++.h>
using namespace std;

string wb[8] = {
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW"
};
string bw[8] = {
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB"
};

string board[50];

int wb_board(int x, int y){
  int count = 0;

  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      if(board[i+x][j+y] != wb[i][j]) count++;
    }
  }

  return count;
}

int bw_board(int x, int y){
  int count = 0;

  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      if(board[i+x][j+y] != bw[i][j]) count++;
    }
  }

  return count;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int min_val = INT_MAX;

  for(int i=0; i<n; i++){
    cin >> board[i];
  }

  for(int i=0; i+8<=n; i++){
    for(int j=0; j+8<=m; j++){
      int tmp;
      
      tmp = min(bw_board(i,j), wb_board(i,j));

      if(min_val > tmp) min_val = tmp;
    }
  }

  cout << min_val;
}
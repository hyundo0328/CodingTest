#include <bits/stdc++.h>
using namespace std;

int stair[302];
int d[302][3];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i=1; i<=n; i++) cin >> stair[i];

  d[1][1] = stair[1]; // 계단 1
  d[1][2] = 0; // 0
  d[2][1] = stair[2]; // 계단 2
  d[2][2] = stair[1] + stair[2]; // 계단 1 + 계단 2

  for(int i=3; i<=n; i++){
    d[i][2] = d[i-1][1] + stair[i];
    d[i][1] = max(d[i-2][1], d[i-2][2]) + stair[i];
  }

  cout << max(d[n][1], d[n][2]);
}
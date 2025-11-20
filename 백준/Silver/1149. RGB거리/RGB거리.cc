#include <bits/stdc++.h>
using namespace std;

int r[1002];
int g[1002];
int b[1002];
int house[1002][4];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i=1; i<=n; i++){
    cin >> r[i];
    cin >> g[i];
    cin >> b[i];
  }

  house[1][1] = r[1]; // 빨간색 시작
  house[1][2] = g[1]; // 초록색 시작
  house[1][3] = b[1]; // 파란색 시작

  for(int i=2; i<=n; i++){
    house[i][1] = min(house[i-1][2], house[i-1][3]) + r[i];
    house[i][2] = min(house[i-1][1], house[i-1][3]) + g[i];
    house[i][3] = min(house[i-1][1], house[i-1][2]) + b[i];
  }

  cout << min({house[n][1], house[n][2], house[n][3]});
}
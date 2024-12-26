#include <bits/stdc++.h>
using namespace std;

int r[1005], g[1005], b[1005];
int d[1005][3];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for(int i=1;i<=t;i++){
    cin >> r[i] >> g[i] >> b[i];
  }
  d[1][0] = r[1]; d[1][1] = g[1]; d[1][2] = b[1];

  for(int i=2;i<=t;i++){
    d[i][0] = min(d[i-1][1], d[i-1][2])+r[i];
    d[i][1] = min(d[i-1][0], d[i-1][2])+g[i];
    d[i][2] = min(d[i-1][0], d[i-1][1])+b[i];
  }

  cout << min({d[t][0], d[t][1], d[t][2]});
}
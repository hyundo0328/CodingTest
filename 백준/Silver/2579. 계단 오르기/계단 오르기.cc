#include <bits/stdc++.h>
using namespace std;

int s[305];
int n;
int d[305][3];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for(int i=1;i<=t;i++){
    cin >> s[i];
  }
  d[1][1] = s[1];
  d[2][1] = s[2];
  d[2][2] = s[1] + s[2];

  for(int i=3;i<=t;i++){
    d[i][1] = max(d[i-2][1], d[i-2][2])+s[i];
    d[i][2] = d[i-1][1]+s[i];
  }

  cout << max(d[t][1], d[t][2]);
}
#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  long long d[92];
  d[1] = 1; d[2] = 1;

  for(int i=3; i<=90; i++) d[i] = d[i-1] + d[i-2];

  cout << d[n];
}
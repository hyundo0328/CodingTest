#include <bits/stdc++.h>
using namespace std;

long long d[92];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  d[0] = 0; d[1] = 1;
  for(int i=2; i<=90; i++) d[i] = d[i-1] + d[i-2];

  int n; cin >> n;
  cout << d[n];
}
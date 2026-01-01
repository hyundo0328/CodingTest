#include <bits/stdc++.h>
using namespace std;

long long dp[1000001];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  dp[1] = 1; // 1
  dp[2] = 2; // 1+1, 2
  dp[3] = 4; // 1+1+1, 1+2, 2+1, 3

  for(int i=4; i<=1000000; i++) dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;

  int t; cin >> t;
  while(t--){
    int num; cin >> num;

    cout << dp[num] << '\n';
  }
}
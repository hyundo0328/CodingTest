#include <bits/stdc++.h>
using namespace std;

long dp[92];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  dp[1] = 1; dp[2] = 1;
  for(int i=3; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }

  cout << dp[n];
}
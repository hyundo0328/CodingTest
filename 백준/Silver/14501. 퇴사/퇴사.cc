#include <bits/stdc++.h>
using namespace std;

int t[16];
int p[16];
int dp[16];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i=1; i<=n; i++) cin >> t[i] >> p[i];

  for(int i=n; i>=1; i--){
    if(i-1+t[i] <= n) dp[i] = max(dp[i+t[i]] + p[i], dp[i+1]);
    else dp[i] = dp[i+1];
  }

  cout << *max_element(dp, dp+n+1);
}
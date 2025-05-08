#include <bits/stdc++.h>
using namespace std;

int num[100002];
int dp[100002];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i=1; i<=n; i++) cin >> num[i];

  for(int i=1; i<=n; i++){
    dp[i] = max(0, dp[i-1]) + num[i];
  }

  cout << *max_element(dp+1, dp+n+1);
  // for(int i=1; i<=n; i++) cout << dp[i] << " ";
}
#include <bits/stdc++.h>
using namespace std;

long long dp[1000001];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  dp[0] = 0; dp[1] = 1;
  for(int i=2; i<=1000000; i++){
    dp[i] = dp[i-1] + dp[i-2];
    dp[i] %= 1000000000;
  }

  int n; cin >> n;
  if(n == 0) {
    cout << 0 << '\n' << 0;
    
    return 0;
  }

  if(n > 0 || (n < 0 && abs(n) % 2 != 0)) cout << 1 << '\n';
  else cout << -1 << '\n';
  
  cout << dp[abs(n)] % 1000000000;
}
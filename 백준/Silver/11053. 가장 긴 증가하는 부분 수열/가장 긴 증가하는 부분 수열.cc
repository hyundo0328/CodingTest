#include <bits/stdc++.h>
using namespace std;

int n;
int num[1001];
int dp[1001];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) cin >> num[i];

  for(int i=0; i<n; i++){
    for(int j=0; j<i; j++){
      if(num[i] > num[j]) dp[i] = max(dp[i], dp[j] + 1);
    }
  }

  cout << *max_element(dp, dp + n) + 1;
}
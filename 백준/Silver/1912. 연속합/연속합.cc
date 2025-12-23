#include <bits/stdc++.h>
using namespace std;

int arr[100002];
int dp[100002];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i=0; i<n; i++) cin >> arr[i];

  dp[0] = arr[0];
  for(int i=1; i<n; i++) dp[i] = max(0, dp[i-1]) + arr[i];

  cout << *max_element(dp, dp+n);
}
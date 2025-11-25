#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  
  if(k == 0) {
    cout << 1;
    return 0;
  }

  int ans = 1;
  for(int num = n; num >= n-k+1; num--) ans *= num;
  for(int num = k; num >= 1; num--) ans /= num;

  cout << ans;
}
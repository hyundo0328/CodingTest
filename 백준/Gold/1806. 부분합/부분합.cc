#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int a[100001];
  int mn = INT_MAX;
  int n, s;
  cin >> n >> s;

  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  int en = 0, total = a[0];
  for(int st=0; st<n; st++){
    while(en<n && total<s){
      en++;
      if(en != n) total += a[en];
    }

    if(en == n) break;
    mn = min(mn, en-st+1);
    total -= a[st];
  }

  if(mn == INT_MAX) mn = 0;
  cout << mn;
}
#include <bits/stdc++.h>
using namespace std;

long long a[100001];
long long x, y;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  long long ans = LONG_LONG_MAX;
  int st=0, en=n-1;
  while(st < en){
    int val = a[st]+a[en];

    if(abs(val) <= abs(ans)) {
      ans = val;
      x = a[st];
      y = a[en];
    }

    if(val < 0){
      st++;
    } else {
      en--;
    }
  }

  cout << x << ' ' << y;
}
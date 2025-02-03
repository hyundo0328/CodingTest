#include <bits/stdc++.h>
using namespace std;

int a[100001];
int mn = INT_MAX;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);

  int en = 0;
  int mn = INT_MAX;
  for(int st=0; st<n; st++){
    while(a[en]-a[st] < m) en++;
    if(en==n) break;
    mn = min(mn,a[en]-a[st]);
  } 

  cout << mn;
}
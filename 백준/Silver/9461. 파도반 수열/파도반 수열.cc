#include <bits/stdc++.h>
using namespace std;

long long tri[102];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  tri[1]= 1; tri[2] = 1; tri[3] = 1;

  for(int i=4; i<=100; i++){
    tri[i] = tri[i-2] + tri[i-3];
  }

  int t;
  cin >> t;
  for(int i=0; i<t; i++){
    int n;
    cin >> n;

    cout << tri[n] << '\n';
  }
}
#include <bits/stdc++.h>
using namespace std;

int d[11];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  
  d[1] = 1; // 1
  d[2] = 2; // 1+1, 2
  d[3] = 4; // 1+1+1, 1+2, 2+1, 3

  for(int i=4; i<=10; i++) d[i] = d[i-1] + d[i-2] + d[i-3];

  while(t--){
    int num;
    cin >> num;

    cout << d[num] << '\n';
  }
}
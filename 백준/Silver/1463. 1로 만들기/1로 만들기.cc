#include <bits/stdc++.h>
using namespace std;

int d[1000005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num;
  cin >> num;

  d[1] = 0; d[2] = 1; d[3] = 1;

  for(int i=4; i<=1000000; i++){
    d[i] = d[i-1] + 1;
    if(i%2 == 0){
      d[i] = min(d[i/2] + 1, d[i]);
    }
    if(i%3 == 0){
      d[i] = min(d[i/3] + 1, d[i]);
    }
  }

  cout << d[num];
}
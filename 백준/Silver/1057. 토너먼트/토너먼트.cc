#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int k, l, round = 0;
  cin >> k >> l;
  while(k != l){
    k = (k+1)/2;
    l = (l+1)/2;
    round++;
  }

  cout << round;
}
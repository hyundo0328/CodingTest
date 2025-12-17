#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  int cnt = 0;
  bool check[1002];
  fill(check, check+1002, false);
  
  for(int num=2; num<=n; num++){
    if(check[num]) continue;
    for(int p=num; p<=n; p+=num){
      if(check[p]) continue;

      check[p] = true;
      cnt++;

      if(cnt == k){
        cout << p;
        return 0;
      }
    }
  }
}
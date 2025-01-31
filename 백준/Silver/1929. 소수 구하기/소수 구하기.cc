#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
  if(n==1) return false;
  for(int j=2;j*j<=n;j++){
    if(n%j == 0){
      return false;
    }
  }

  return true;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int m, n;
  cin >> m >> n;

  for(int i=m; i<=n; i++){
    bool flag = false;
    flag = isPrime(i);

    if(flag) cout << i << '\n';
  }

  return 0;
}
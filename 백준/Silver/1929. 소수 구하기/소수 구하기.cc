#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for(int num = n; num <= m; num++){
    if(num == 1) continue;
    
    bool flag = false;
    for(int i=2; i*i <=num; i++){
      if(num % i == 0){
        flag = true;
        break;
      }
    }

    if(!flag) cout << num << '\n';
  }

  return 0;
}
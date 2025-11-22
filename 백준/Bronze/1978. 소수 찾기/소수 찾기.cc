#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, count = 0;
  cin >> t;

  while(t--){
    int num;
    cin >> num;

    if(num == 1) continue;

    bool flag = false;
    for(int i=2; i*i <= num; i++){
      if(num % i == 0) {
        flag = true;
        break;
      }
    }

    if(!flag) count++;
  }
  cout << count;

  return 0;
}
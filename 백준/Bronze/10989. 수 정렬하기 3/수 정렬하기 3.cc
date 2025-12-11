#include <bits/stdc++.h>
using namespace std;

int num_arr[10002];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while(n--){
    int tmp; cin >> tmp;
    num_arr[tmp]++;
  }

  for(int i=1; i<=10000; i++){
    while(num_arr[i]-- > 0) cout << i << '\n';
  }
}
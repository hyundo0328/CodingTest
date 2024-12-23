#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9];

void func(int num){
  if(num == m){
    for(int i=0; i<m; i++){
      cout << arr[i] << ' ';
    }

    cout << '\n';
    return;
  }

  int start;
  if(num != 0) {
    start = arr[num-1];
  } else {
    start = 1;
  }

  for(int i=start; i<=n; i++){
    arr[num] = i;
    func(num+1);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  func(0);
}
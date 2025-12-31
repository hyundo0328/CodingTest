#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9];
int num[9];
bool isUsed[9];

void func(int k){
  if(k == m){
    for(int i=0; i<m; i++) cout << arr[i] << ' ';
    cout << '\n';

    return;
  }

  int tmp = 0;
  for(int i=0; i<n; i++){
    if(!isUsed[i] && tmp != num[i]){
      arr[k] = num[i];
      isUsed[i] = true;
      tmp = num[i];
      func(k+1);
      isUsed[i] = false;
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i=0; i<n; i++) cin >> num[i];
  sort(num, num+n);
  func(0);
}
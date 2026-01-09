#include <bits/stdc++.h>
using namespace std;

int num[8];
int arr[8];
int n, m;

void func(int k){
  if(m == k){
    for(int i=0; i<m; i++) cout << num[arr[i]] << ' ';
    cout << '\n';

    return;
  }

  int st;
  if(k == 0) st = 0;
  else st = arr[k-1];

  int tmp = 0;
  for(int i=st; i<n; i++){
    if(tmp != num[i]){
      arr[k] = i;
      tmp = num[i];
      func(k+1);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for(int i=0; i<n; i++) cin >> num[i];
  sort(num, num + n);
  func(0);
}
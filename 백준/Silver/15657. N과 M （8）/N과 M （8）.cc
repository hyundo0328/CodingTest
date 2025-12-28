#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];
int num[8];

void func(int k){
  if(k == m){
    for(int i=0; i<m; i++) cout << num[arr[i]] << ' ';
    cout << '\n';

    return;
  }

  int start;
  if(k==0) start = 0;
  else start = arr[k-1];

  for(int i=start; i<n; i++){
    arr[k] = i;
    func(k+1);
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
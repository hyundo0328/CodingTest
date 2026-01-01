#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9];
int num[9];
bool isUsed[9];

void func(int k){
  if(k == m){
    for(int i=0; i<m; i++) cout << num[arr[i]] << ' ';
    cout << '\n';

    return;
  }

  int st;
  if(k == 0) st = 0;
  else st = arr[k-1]+1;

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
  sort(num, num+n);
  func(0);
}
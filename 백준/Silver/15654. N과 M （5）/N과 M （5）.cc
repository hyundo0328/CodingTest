#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9];
int answer[9];
bool isUsed[9];

void func(int k){
  if(k == m){
    for(int i=0; i<m; i++) cout << answer[i] << ' ';
    cout << '\n';

    return;
  }

  for(int i=0; i<n; i++){
    if(!isUsed[i]){
      answer[k] = arr[i];
      isUsed[i] = true;
      func(k+1);
      isUsed[i] = false;
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i=0; i<n; i++) cin >> arr[i];
  sort(arr, arr+n);

  func(0);
}
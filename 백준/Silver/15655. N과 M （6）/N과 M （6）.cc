#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9];
int answer[9];

void func(int k){
  if(m == k){
    for(int i=0; i<m; i++) cout << arr[answer[i]] << ' ';
    cout << '\n';

    return;
  }

  int start;
  if(k == 0) start = 0;
  else start = answer[k-1] + 1;

  for(int i=start; i<n; i++){
    answer[k] = i;
    func(k+1);
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
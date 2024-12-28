#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n;

  int arr[500001];

  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  sort(arr,arr+n);

  cin >> m;
  for(int j=0;j<m;j++){
    int tmp;
    cin >> tmp;
    cout << binary_search(arr,arr+n,tmp) << ' ';
  }
}
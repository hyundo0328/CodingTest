#include <bits/stdc++.h>
using namespace std;

int arr[100001];
// vector<int> vec;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  sort(arr, arr+n);

  cin >> m;
  for(int i=0;i<m;i++){
    int tmp;
    cin >> tmp;
    cout << binary_search(arr, arr+n, tmp) << '\n';
  }
}
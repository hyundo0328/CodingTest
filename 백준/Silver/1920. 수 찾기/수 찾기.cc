#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[100001];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0;i<n;i++){
    int tmp;
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
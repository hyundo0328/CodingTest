#include <bits/stdc++.h>
using namespace std;

int n, m;
// int arr[100001];
vector<int> vec;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0;i<n;i++){
    int tmp;
    cin >> tmp;
    vec.push_back(tmp);
  }
  // sort(arr, arr+n);
  sort(vec.begin(),vec.end());

  cin >> m;
  for(int i=0;i<m;i++){
    int tmp;
    cin >> tmp;
    cout << upper_bound(vec.begin(),vec.end(),tmp)-lower_bound(vec.begin(),vec.end(),tmp) << '\n';
  }
}
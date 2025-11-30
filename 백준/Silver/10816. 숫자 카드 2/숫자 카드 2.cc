#include <bits/stdc++.h>
using namespace std;

long long arr[500001];
vector<long long> vec;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  for(int i=0; i<n; i++){
    long long tmp; cin >> tmp;
    vec.push_back(tmp);
  }
  sort(vec.begin(), vec.end());

  int m; cin >> m;
  while(m--){
    long long tmp; cin >> tmp;

    cout << upper_bound(vec.begin(), vec.end(), tmp) - lower_bound(vec.begin(), vec.end(), tmp) << " ";
  }

}
#include <bits/stdc++.h>
using namespace std;

int arr[1000005];
vector<int> vec;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i=0; i<n; i++){
    cin >> arr[i];
    vec.push_back(arr[i]);
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());

  for(int i=0; i<n; i++){
    int idx = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
    cout << idx << ' ';
  }
}
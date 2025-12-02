#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while(n--){
    int tmp; cin >> tmp;

    vec.push_back(tmp);
  }
  sort(vec.begin(), vec.end());

  int m; cin >> m;
  while(m--){
    int tmp; cin >> tmp;

    if(binary_search(vec.begin(), vec.end(), tmp)) cout << 1 << ' ';
    else cout << 0 << ' ';
  }
}
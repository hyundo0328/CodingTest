#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<pair<int, int>> vec;

  int x;
  int y;
  for(int i=0;i<n;i++){
    cin >> x >> y;
    vec.push_back({x, y});
  }
  sort(vec.begin(),vec.end());

  for(auto point:vec){
    cout << point.first << ' ' << point.second << '\n';
  }
}
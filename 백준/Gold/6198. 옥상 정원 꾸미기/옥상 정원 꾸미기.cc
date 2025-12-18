#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  stack<pair<long long, int>> building;
  stack<pair<long long, int>> st2;
  for(int i=1; i<=n; i++){
    long long tmp; cin >> tmp;
    building.push({tmp, i});
  }

  long long total = 0;
  st2.push({1000000001, n+1});
  while(!building.empty()){
    long long height = building.top().first;
    int idx = building.top().second;
    building.pop();
    
    while(height > st2.top().first){
      st2.pop();
    }
    total += st2.top().second - idx - 1;
    st2.push({height, idx});
  }

  cout << total;
}
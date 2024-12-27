#include <bits/stdc++.h>
using namespace std;

int d[1000005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  unordered_set<string> s;
  while(t-- > 0){
    string name, type;
    cin >> name >> type;
    if(type == "enter"){
      s.insert(name);
    } else {
      s.erase(name);
    }
  }
  
  vector<string> ans(s.begin(), s.end());
  sort(ans.begin(), ans.end(), greater<string>());
  for(auto x : ans) cout << x << '\n';
}
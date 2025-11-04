#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  unordered_set<string> us;
  for(int i=0; i<n; i++){
    string name, log;
    cin >> name >> log;

    if(log == "enter") us.insert(name);
    else us.erase(name);
  }
  

  vector<string> ans(us.begin(), us.end());
  sort(ans.begin(), ans.end(), greater<string>());
  
  for(auto x : ans) cout << x << '\n';
}
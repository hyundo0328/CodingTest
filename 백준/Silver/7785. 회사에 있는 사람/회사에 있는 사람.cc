#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  set<string> set;
  while(n--){
    string name, log;
    cin >> name >> log;
    if(log == "enter") set.insert(name);
    else set.erase(name);
  }

  auto it = set.end();
  while(it != set.begin()){
    advance(it, -1);
    cout << *it << '\n';
  }
}
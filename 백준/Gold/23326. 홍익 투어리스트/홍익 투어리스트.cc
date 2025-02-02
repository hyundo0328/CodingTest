#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  set<int> hu;
  int n, q, location = 1;

  cin >> n >> q;
  for(int i=1; i<=n; i++){
    int l;
    cin >> l;

    if(l == 1) hu.insert(i);
  }

  while(q-- > 0){
    int cmd;
    cin >> cmd;

    if(cmd == 1){
      int i;
      cin >> i;

      if(hu.find(i) != hu.end()){
        hu.erase(i);
      } else {
        hu.insert(i);
      }
    } else if (cmd == 2){
      int x;
      cin >> x;

      location = (location + x - 1) % n + 1;
    } else if (cmd == 3){
      if(hu.empty()){
        cout << -1 << '\n';
      } else {
        auto close = hu.lower_bound(location);

        if(close != hu.end()){
          cout << *close - location << '\n';
        } else {
          cout << n - location + *hu.begin() << '\n';
        }
      }
    }
  }
}
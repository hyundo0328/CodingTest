#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, k;
  cin >> t;
  
  while(t-- > 0){
    multiset<int> ms;
    cin >> k;
    while(k-- > 0){
      char iord;
      int num;
      cin >> iord >> num;
      if(iord == 'I'){
        ms.insert(num);
      } else if(iord == 'D') {
        set<int>::iterator max = ms.end();
        set<int>::iterator min = ms.begin();
        if(ms.size() == 0) continue;
        if(num == 1){
          ms.erase(prev(ms.end()));
        } else {
          ms.erase(ms.begin());
        }
      }
    }
    if(ms.size() == 0) {
      cout << "EMPTY" << '\n';
    } else {
      cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }
  }
}
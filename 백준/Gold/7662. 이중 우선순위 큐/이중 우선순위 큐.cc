#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    int k; cin >> k;

    multiset<int> ms;
    while(k--){
      char query; int num;
      cin >> query >> num;

      if(query == 'I') ms.insert(num);
      if(query == 'D'){
        if(!ms.empty()){
          if(num == 1) ms.erase(prev(ms.end()));
          else ms.erase(ms.begin());
        }
      }
    }
    
    if(ms.empty()) cout << "EMPTY\n";
    else cout << *prev(ms.end()) << " " << *ms.begin() << '\n';
  }
}
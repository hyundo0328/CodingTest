#include <bits/stdc++.h>
using namespace std;

int level[100002];
set<int> problem[102];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while(n--){
    int p, l;
    cin >> p >> l;

    level[p] = l;
    problem[l].insert(p);
  }

  int m; cin >> m;
  while(m--){
    string query; cin >> query;

    if(query == "add"){
      int p, l;
      cin >> p >> l;

      level[p] = l;
      problem[l].insert(p);
    } else if (query == "recommend"){
      int x; cin >> x;
      if(x == 1){
        for(int i=100; i>=1; i--){
          if(problem[i].empty()) continue;
          cout << *prev(problem[i].end()) << '\n';
          break;
        }
      } else {
        for(int i=1; i<=100; i++){
          if(problem[i].empty()) continue;
          cout << *problem[i].begin() << '\n';
          break;
        }
      }
    } else if (query == "solved"){
      int p; cin >> p;
      int l = level[p];
      problem[l].erase(p);
    }
  }
}
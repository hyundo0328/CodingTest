#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int probLevel[100002];
  set<int> probByLevel[102];

  for(int i=0;i<n;i++){
    int p, l;
    cin >> p >> l;
    probLevel[p] = l;
    probByLevel[l].insert(p);
  }

  int m;
  cin >> m;
  for(int i=0;i<m;i++){
    string c;
    cin >> c;
    if(c == "add"){
      int p, l;
      cin >> p >> l;

      probLevel[p] = l;
      probByLevel[l].insert(p);
    } else if (c == "recommend") {
      int x;
      cin >> x;

      if(x == 1){
        for(int i=100; i>=0; i--){
          if (probByLevel[i].empty()) continue;
          cout << *(prev(probByLevel[i].end())) << '\n';
          break;
        }
      } else {
        for(int i=0; i<101; i++){
          if (probByLevel[i].empty()) continue;
          cout << *(probByLevel[i].begin()) << '\n';
          break;
        }
      }
    } else if (c == "solved"){
      int p;
      cin >> p;
      probByLevel[probLevel[p]].erase(p);
    }
  }
}
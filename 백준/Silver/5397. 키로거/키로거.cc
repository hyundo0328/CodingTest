#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i=0;i<n;i++){
    string str;
    cin >> str;

    list<char> L;
    auto cursor = L.begin();
    
    for (auto c:str){
      if(c == '<'){
        if(cursor != L.begin()) cursor--;
      } else if (c == '>'){
        if(cursor != L.end()) cursor++;
      } else if (c == '-'){
        if(cursor != L.begin()) {
          cursor--;
          cursor = L.erase(cursor);
        }
      } else {
        L.insert(cursor, c);
      }
    }
    
    for(auto c:L) cout << c;
    if(i != n-1){
      cout << '\n';
    }
  }
}
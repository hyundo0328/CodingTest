#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  while(n--){
    string str;
    cin >> str;

    stack<char> s;
    bool flag = false;
    for(char c:str){
      if(c == '(') s.push(c);
      else{
        if(!s.empty()) s.pop();
        else{
          flag = true;
          break;
        }
      }
    }

    if(!s.empty()) flag = true;

    if(flag) cout << "NO\n";
    else cout << "YES\n";
  }
}
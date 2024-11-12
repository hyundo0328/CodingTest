#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i=0;i<n;i++){
    string s;
    cin >> s;

    stack<char> c_stack;
    bool inValid = true;
    for(auto c:s) {
      if(c == '(') {
        c_stack.push(c);
      } else {
        if(c_stack.empty()) {
          inValid = false;
          break;
        } else {
          c_stack.pop();
        }
      }
    }

    if (!c_stack.empty()) inValid = false;
    if (inValid) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  
  
  return 0;
}
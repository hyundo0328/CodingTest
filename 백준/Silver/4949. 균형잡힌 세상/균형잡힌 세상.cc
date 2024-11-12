#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(true){
    string s;
    getline(cin, s);

    if(s == ".") break;

    stack<char> c_stack;
    bool isValid = true;
    for(auto c : s){
      if(c == '(' || c == '[') {
        c_stack.push(c);
      } else if (c == ')') {
        if(c_stack.empty()) {
          isValid = false;
          break;
        }
        if (c_stack.top() == '(') {
          c_stack.pop();
          continue;
        } else {
          isValid = false;
          break;
        }
      } else if (c == ']') {
        if(c_stack.empty()) {
          isValid = false;
          break;
        }
        if (c_stack.top() == '[') {
          c_stack.pop();
          continue;
        } else {
          isValid = false;
          break;
        }
      }
    }
    if(!c_stack.empty()){
      isValid = false;
    }
    if(isValid) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
  
  return 0;
}
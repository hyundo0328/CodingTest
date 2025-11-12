#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(true){
    string str;
    getline(cin, str);

    if(str == ".") break;
    stack<char> s;

    bool flag = false;
    for(char c:str){
      if(c == '(' || c == '[') s.push(c);
      else if(c == ')'){
        if(s.empty() || s.top() != '('){
          flag = true;
          break;
        }
        s.pop();
      } else if(c == ']'){
        if(s.empty() || s.top() != '['){
          flag = true;
          break;
        }
        s.pop();
      }
    }

    if(!s.empty()) flag = true;
    flag ? cout << "no\n" : cout << "yes\n";
  }

}
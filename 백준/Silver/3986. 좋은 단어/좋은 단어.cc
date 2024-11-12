#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int count = 0;
  for(int i=0;i<n;i++){
    string s;
    cin >> s;

    bool isValid = true;
    stack<char> c_stack;

    for(auto c:s){
      if (!c_stack.empty() && c_stack.top() == c) {
        c_stack.pop();
      } else {
        c_stack.push(c);
      }
    }
    if(c_stack.empty()) count++;
  }
  cout << count;
  
  return 0;
}
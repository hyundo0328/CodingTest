#include <bits/stdc++.h>
using namespace std;

string str;
stack<char> st;
int total = 0, num = 1;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;

  for(int i=0; i<str.size(); i++){
    if(str.at(i) == '('){
      num *= 2;
      st.push(str.at(i));
    } else if(str.at(i) == '['){
      num *= 3;
      st.push(str.at(i));
    } else if(str.at(i) == ')'){
      if(st.empty() || st.top() != '('){
        cout << 0;
        return 0;
      }
      if(str.at(i-1) == '(') total += num;
      st.pop();
      num /= 2;
    } else if(str.at(i) == ']'){
      if(st.empty() || st.top() != '['){
        cout << 0;
        return 0;
      }
      if(str.at(i-1) == '[') total += num;
      st.pop();
      num /= 3;
    }
  }

  if(!st.empty()) cout << 0;
  else cout << total;
}
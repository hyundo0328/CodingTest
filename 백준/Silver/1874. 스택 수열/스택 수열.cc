#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  
  int num = 1;
  bool flag = false;
  stack<int> s;

  string st;
  while(n--){
    int tmp; cin >> tmp;

    while(num <= tmp){
      s.push(num);
      num++;
      st.append("+\n");
    }

    if(s.top() == tmp){
      s.pop();
      st.append("-\n");
    } else {
      flag = true;
    }
  }

  if(!flag) cout << st;
  else cout << "NO";
}
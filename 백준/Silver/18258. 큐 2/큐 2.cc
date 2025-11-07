#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  queue<int> q;
  for(int i=0; i<n; i++){
    string cmd;
    cin >> cmd;

    if(cmd == "push"){
      int num; cin >> num;
      q.push(num);
    } else if (cmd == "pop"){
      if(q.empty()) cout << -1 << '\n';
      else {
        cout << q.front() << '\n';
        q.pop();
      }
    }
    else if (cmd == "front") q.empty() ? cout << -1 << '\n' : cout << q.front() << '\n';
    else if (cmd == "back") q.empty() ? cout << -1 << '\n' : cout << q.back() << '\n';
    else if (cmd == "size") cout << q.size() << '\n';
    else if (cmd == "empty") q.empty() ? cout << 1 << '\n' : cout << 0 << '\n';
  }

  return 0;
}
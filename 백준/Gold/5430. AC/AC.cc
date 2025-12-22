#include <bits/stdc++.h>
using namespace std;

deque<int> stringToDeque(string str){
  deque<int> dq;
  string tmp = "";

  for(int i=1; i<str.length(); i++){
    if(isdigit(str.at(i))) tmp += str.at(i);
    else {
      if(!tmp.empty()){
        dq.push_back(stoi(tmp));
        tmp = "";
      }
    }
  }
  return dq;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    string cmd; cin >> cmd;
    int n; cin >> n;
    string str; cin >> str;

    bool isError = false;
    bool isReverse = false;
    deque<int> dq = stringToDeque(str);
    for(char c:cmd){
      if(c == 'R') isReverse = !isReverse;
      else {
        if(dq.empty()){
          isError = true;
          break;
        }
        if(!isReverse) dq.pop_front();
        else dq.pop_back();
      }
    }

    if(isError) cout << "error\n";
    else{
      if(isReverse) reverse(dq.begin(), dq.end());

      cout << "[";
      for(int i=0; i<dq.size(); i++){
        cout << dq[i];
        if(i+1 != dq.size()) cout << ',';
      }
      cout << "]\n";
    }
  }

}
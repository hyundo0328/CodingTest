#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string stick; cin >> stick;
  stack<char> st;
  
  int total = 0;
  for(int i=0; i<stick.size(); i++){
    if(stick[i] == '(') st.push(stick[i]);
    else if(stick[i-1] == '(' && stick[i] == ')'){
      st.pop();
      total += st.size();
    } else{
      total++;
      st.pop();
    }
  }

  cout << total;
}
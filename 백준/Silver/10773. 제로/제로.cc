#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int k;
  cin >> k;

  stack<int> s;
  while(k--){
    int num; cin >> num;

    num != 0 ? s.push(num) : s.pop();
  }

  int sum = 0;
  while(!s.empty()){
    sum += s.top();
    s.pop();
  }

  cout << sum;
}
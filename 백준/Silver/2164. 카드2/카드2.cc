#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  queue<int> q;
  for(int i=1;i<=n;i++){
    q.push(i);
  }

  while(q.size()!=1){
    q.pop();
    int num = q.front();
    q.push(num);
    q.pop();
  }
  cout << q.front();

  return 0;
}
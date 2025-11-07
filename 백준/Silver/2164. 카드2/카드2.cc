#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  if(n == 1){
    cout << 1;
    return 0;
  }

  queue<int> q;
  for(int i=1; i<=n; i++){
    q.push(i);
  }

  while(q.size() > 1){
    q.pop();
    int num = q.front(); 
    q.pop();
    q.push(num);
  }
  cout << q.front();

  return 0;
}
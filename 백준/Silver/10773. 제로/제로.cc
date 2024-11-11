#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  int count = 0;

  stack<int> s;
  for(int i=0;i<n;i++){
    int num;
    cin >> num;

    if(num != 0){
      s.push(num);
      count += num;
    } else {
      count -= s.top();
      s.pop();
    }
  }
  cout << count;

  return 0;
}
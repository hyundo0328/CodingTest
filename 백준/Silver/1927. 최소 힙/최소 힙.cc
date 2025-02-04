#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  priority_queue<int, vector<int>, greater<int>> pq;

  int n;
  cin >> n;

  int num;
  while(n-- > 0){
    cin >> num;

    if(num == 0){
      if(pq.empty()){
        cout << 0 << '\n';
      } else {
        cout << pq.top() << '\n';
        pq.pop();
      }
    } else {
      pq.push(num);
    }
  }
}
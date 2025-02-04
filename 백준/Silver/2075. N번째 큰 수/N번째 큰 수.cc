#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  priority_queue<int, vector<int>, greater<int>> pq;

  int n;
  cin >> n;

  int num;
  for(int i=0;i<n*n;i++){
    cin >> num;
    pq.push(num);
    if(pq.size() > n) pq.pop();
  }

  cout << pq.top();
}
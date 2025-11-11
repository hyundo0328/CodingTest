#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  deque<int> dq;
  for(int i=1; i<=n; i++)  dq.push_back(i);

  int count = 0;
  while(m--){
    int num; cin >> num;

    int idx = find(dq.begin(), dq.end(), num) - dq.begin();
    if(idx <= dq.size()/2){
      while(dq.at(0) != num){
        int tmp = dq.front(); dq.pop_front();
        dq.push_back(tmp);
        count++;
      }
      dq.pop_front();
    } else {
      while(dq.at(0) != num){
        int tmp = dq.back(); dq.pop_back();
        dq.push_front(tmp);
        count++;
      }
      dq.pop_front();
    }
  }

  cout << count;
  
}
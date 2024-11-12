#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  deque<int> dq;
  int n, m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    dq.push_back(i);
  }

  int count = 0;
  for(int i=0;i<m;i++){
    int num;
    cin >> num;

    int idx = find(dq.begin(), dq.end(), num) - dq.begin();
    while(dq.front() != num){
      if (idx < dq.size() - idx) { 
        dq.push_back(dq.front());
        dq.pop_front();
      }
      else {
        dq.push_front(dq.back());
        dq.pop_back();
      }
      count++;
    }
    dq.pop_front();
  }
  cout << count;
}
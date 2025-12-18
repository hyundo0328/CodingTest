#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n; cin >> n;

  stack<pair<int, int>> st;
  st.push({100000001, 0});

  for(int i=1; i<=n; i++){
    int height; cin >> height;

    while(st.top().first < height) st.pop();

    cout << st.top().second << ' ';
    st.push({height, i});
  }
}
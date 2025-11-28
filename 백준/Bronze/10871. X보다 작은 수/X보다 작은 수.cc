#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;

  while(n--){
    int num; cin >> num;

    if(x > num) cout << num << ' ';
  }
}

#include <bits/stdc++.h>
using namespace std;

int t, n;

unordered_map<string, vector<string>> clothes;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;

  int count;
  string c_name, c_type;
  while(t-- > 0){
    cin >> n;
    while(n-- > 0){
      cin >> c_name >> c_type;

      clothes[c_type].push_back(c_name);
    }

    count = 1;
    for(auto ct : clothes) count *= (ct.second.size()+1);

    cout << count-1 << '\n';

    clothes.clear();
  }
}
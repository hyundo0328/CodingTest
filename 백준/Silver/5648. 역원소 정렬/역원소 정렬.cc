#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  string str;
  vector<long long> vec;
  
  for(int i=0;i<n;i++){
    cin >> str;
    reverse(str.begin(), str.end());
    vec.push_back(stoll(str));
  }
  sort(vec.begin(),vec.end());

  for(auto num:vec){
    cout << num << '\n';
  }
}
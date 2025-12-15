#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<string> vec;

  int n; cin >> n;
  while(n--){
    string tmp; cin >> tmp;
    vec.push_back(tmp);
  }

  sort(vec.begin(), vec.end(), [&](string a, string b){
    if(a.size() != b.size()) return a.size() < b.size(); // 1순위: 길이가 짧은 것부터

    return a < b; // 2순위: 사전 순으로
  });
  vec.erase(unique(vec.begin(), vec.end()), vec.end()); // 중복 제거

  for(string word:vec) cout << word << '\n';
}
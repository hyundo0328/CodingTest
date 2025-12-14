#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n; cin >> n;
  vector<string> dic;

  for(int i=0; i<n; i++) {
    string tmp; cin >> tmp;
    dic.push_back(tmp);
  }

  sort(dic.begin(), dic.end(), [&](string a, string b){
    if(a.size() != b.size()) return a.size() < b.size(); // 1순위: 길이가 다를 때
    
    int total_a = 0, total_b = 0;
    for(char c:a) if(isdigit(c)) total_a += c-'0'; // a의 길이
    for(char c:b) if(isdigit(c)) total_b += c-'0'; // b의 길이
    if(total_a != total_b) return total_a < total_b; // 2순위: 숫자 합이 더 클 때
    
    return a < b;
  });

  for(string word:dic) cout << word << '\n';
}
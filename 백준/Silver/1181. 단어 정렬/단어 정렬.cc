#include <bits/stdc++.h>
using namespace std;

bool cmp(string& a, string& b){
  int a_size = a.length();
  int b_size = b.length();
  if(a_size != b_size) return a_size < b_size;
  return a < b;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  string str;
  vector<string> vec;
  
  for(int i=0;i<n;i++){
    cin >> str;
    vec.push_back(str);
  }
  sort(vec.begin(),vec.end(), cmp);
  vec.erase(unique(vec.begin(), vec.end()), vec.end());

  for(auto word:vec){
    cout << word << '\n';
  }
}
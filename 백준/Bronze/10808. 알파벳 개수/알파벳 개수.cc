#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int alpha[26] = {0,};
  string s;
  cin >> s;
  for(auto c : s){
    alpha[c-'a']++;
  }
  for(int i = 0; i < 26; i++)
    cout << alpha[i] << ' ';

  return 0;
}
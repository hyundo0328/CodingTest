#include <bits/stdc++.h>
using namespace std;

int alphabet[26];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str;
  cin >> str;

  for(int i=0; i<str.length(); i++) alphabet[str.at(i) - 'a']++;

  for(auto count:alphabet) cout << count << " ";
  
}
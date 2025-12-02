#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  unordered_map<string, string> hash;
  while(n--){
    string link, password;
    cin >> link >> password;

    hash[link] = password;
  }

  while(m--){
    string link;
    cin >> link;

    cout << hash[link] << '\n';
  }
}
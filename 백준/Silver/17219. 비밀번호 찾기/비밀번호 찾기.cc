#include <bits/stdc++.h>
using namespace std;

int n, m;

unordered_map<string, string> password;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  string net, pw;
  while(n-- > 0){
    cin >> net >> pw;

    password[net] = pw;
  }

  while(m-- > 0){
    cin >> net;

    cout << password[net] << '\n';
  }
}
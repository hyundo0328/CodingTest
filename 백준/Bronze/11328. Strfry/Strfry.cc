#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  for(int i=0; i<n; i++){
    string a, b;
    cin >> a >> b;

    int check[26] = {};

    for(auto c:a) check[c-'a']++;
    for(auto c:b) check[c-'a']--;

    bool flag = false;
    for(int n:check) if(n != 0) flag = true;

    flag ? cout << "Impossible\n" : cout << "Possible\n";
  }

}
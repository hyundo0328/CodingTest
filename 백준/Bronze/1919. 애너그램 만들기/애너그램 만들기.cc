#include <bits/stdc++.h>
using namespace std;

int check[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

  string a, b;
  cin >> a >> b;

  for(auto c:a) check[c-'a']++;
  for(auto c:b) check[c-'a']--;

  int count = 0;
  for(int ch:check) count += abs(ch);

  cout << count;
}
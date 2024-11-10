#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string init;
  cin >> init;

  list<char> L;
  for (auto c : init) L.push_back(c);
  auto cursor = L.end();

  int n;
  cin >> n;

  for(int i=0;i<n;i++) {
    char editor;
    cin >> editor;
    if (editor == 'P') {
      char c;
      cin >> c;
      L.insert(cursor, c);
    }
    else if (editor == 'L') {
      if (cursor != L.begin()) cursor--;
    }
    else if (editor == 'D') {
      if (cursor != L.end()) cursor++;
    }
    else if (editor == 'B') {
      if (cursor != L.begin()) {
        cursor--;
        cursor = L.erase(cursor);
      }
    }
  }
  for (auto c : L) cout << c;
}
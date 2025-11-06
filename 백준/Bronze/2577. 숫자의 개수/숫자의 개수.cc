#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  cin >> a >> b >> c;

  long long total = a*b*c;
  string total_st = to_string(total);

  for(int i=0; i<total_st.length(); i++) cnt[total_st.at(i) - '0']++;
  for(int count:cnt) cout << count << '\n';

}
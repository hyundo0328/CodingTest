#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n[26] = {0,};

  int count = 0;
  string a, b;
  cin >> a;
  for(auto i:a){
    n[i-'a']++;
    count++;
  }
  cin >> b;
  for(auto i:b){
    if(n[i-'a'] != 0){
      n[i-'a']--;
      count--;
    } else {
      count++;
    }
  }
  cout << count;
	
  return 0;
}
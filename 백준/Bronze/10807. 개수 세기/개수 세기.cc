#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

  vector<int>num(n);
  for(auto& i:num){
    cin >> i;
  }

  int v;
  cin >> v;

  int count = 0;
  for(int i=0;i<num.size(); i++){
    if(num[i] == v) count++;
  }
  cout << count;
	
  return 0;
}
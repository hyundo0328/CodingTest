#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int>v1(n);
	for (auto& i : v1)
		cin >> i;
	
  int x;
	cin >> x;
	
  int cnt = 0;
  vector<int>v2(x,0);
	for (int i = 0; i < v1.size(); i++) {
		if (x > v1[i] && v2[x - v1[i]]) // x > v1[i] 조건에 유의합시다! 런타임에러가 날 수 있어요
			cnt++;
		else if (x > v1[i])
			v2[v1[i]] = 1;
	}
  
	cout << cnt;
}
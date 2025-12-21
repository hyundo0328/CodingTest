#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int from, int tmp, int to) {
	if (n == 1) {
		cout << from << " " << to << "\n";
	} else {
		hanoi(n - 1, from, to, tmp);
		cout << from << " " << to << "\n";
		hanoi(n - 1, tmp, from, to);
	}
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k; cin >> k;

  cout << int(pow(2, k)) - 1 << "\n";
  hanoi(k, 1, 2, 3);
}
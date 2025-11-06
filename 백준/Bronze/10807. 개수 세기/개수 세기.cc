#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
  cin >> n;

  vector<int> vec;
  for(int i=0; i<n; i++){
    int num;
    cin >> num;
    vec.push_back(num);
  }

  int v;
  cin >> v;

  cout << count(vec.begin(), vec.end(), v);
}
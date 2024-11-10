#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

  int num[2][6] = {0,};
  for(int i=0;i<n;i++){
    int s, y;
    cin >> s >> y;
    num[s][y-1]++;
  }

  int count = 0;
  for(int i=0;i<6;i++){
    count += (num[0][i])/k;
    count += (num[1][i])/k;
    if(num[0][i]%k != 0) count++;
    if(num[1][i]%k != 0) count++;
  }
  cout << count;
	
  return 0;
}
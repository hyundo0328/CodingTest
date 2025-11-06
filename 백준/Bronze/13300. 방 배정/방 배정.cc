#include <bits/stdc++.h>
using namespace std;

int students[7][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

  for(int i=0; i<n; i++){
    int gender, grade;
    cin >> gender >> grade;

    students[grade][gender]++;
  }

  int count = 0;
  for(int i=1; i<=6; i++){
    int boy = students[i][1];
    int girl = students[i][0];

    count += (boy%k == 0 ? boy/k : boy/k+1);
    count += (girl%k == 0 ? girl/k : girl/k+1);
  }

  cout << count;
}
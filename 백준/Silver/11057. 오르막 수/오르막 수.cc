#include <bits/stdc++.h>
using namespace std;

long long num[1001][11];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  // 점화식 초기값
  for(int i=1; i<=10; i++) num[1][i] = i;

  for(int i=2; i<=1000; i++){
    // 첫째 자리가 9일때: 1개, 둘째 자리가 8일때: 이전 9의 경우의수 + 이전 8의 경우의수
    num[i][1] = 1; num[i][2] = num[i-1][1] + num[i-1][2];

    for(int j=3; j<=10; j++) num[i][j] = (num[i-1][j] + num[i][j-1]) % 10007;
  }

  int n; cin >> n;
  cout << num[n][10];
}
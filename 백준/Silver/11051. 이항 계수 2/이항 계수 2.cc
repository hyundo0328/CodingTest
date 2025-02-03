#include <bits/stdc++.h>
using namespace std;

int nCk[1002][1002]; // nCk = (n-1)Ck + (n-1)C(k-1)

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  nCk[1][0] = 1; nCk[1][1] = 1;
  for(int i=2; i<=n; i++){
    nCk[i][0] = 1;
    nCk[i][i] = 1;
    for(int j=1; j<i; j++){
      nCk[i][j] = (nCk[i-1][j] + nCk[i-1][j-1]) % 10007;
    }
  }

  cout << nCk[n][k];
}
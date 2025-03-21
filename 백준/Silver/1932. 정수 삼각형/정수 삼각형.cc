#include <bits/stdc++.h>
using namespace std;

int d[502][502];
int sum[502][502];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      int x;
      cin >> x;

      if(i == 1) {
        d[i][j] = x;
        continue;
      }
      
      if(i > 1 && j == 1){
        d[i][j] = x + d[i-1][j];
        continue;
      }

      if(i > 1 && i == j){
        d[i][j] = x + d[i-1][j-1];
        continue;
      }

      d[i][j] = x + max(d[i-1][j-1], d[i-1][j]);
    }
  }

  cout << *max_element(d[n]+1, d[n]+n+ 1);
}
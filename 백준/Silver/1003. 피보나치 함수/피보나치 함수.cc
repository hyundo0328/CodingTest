#include <bits/stdc++.h>
using namespace std;

int t;
int fibonacci[42][2];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  fibonacci[0][0] = 1; fibonacci[0][1] = 0;
  fibonacci[1][0] = 0; fibonacci[1][1] = 1;
  
  for(int i=2;i<=40;i++){
    fibonacci[i][0] = fibonacci[i-1][0] + fibonacci[i-2][0];
    fibonacci[i][1] = fibonacci[i-1][1] + fibonacci[i-2][1];
  }

  cin >> t;
  while(t-- > 0){
    int n;
    cin >> n;
    cout << fibonacci[n][0] << ' ' << fibonacci[n][1] << '\n';
  }
}
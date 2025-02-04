#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int line = 1;
  while(n-line > 0){
    n -= line;
    line++;
  }
  
  if(line%2 == 0) cout << n << '/' << line+1-n;
  else cout << line+1-n << '/' << n;
}
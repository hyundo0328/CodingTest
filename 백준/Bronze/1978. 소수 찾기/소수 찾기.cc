#include <bits/stdc++.h>
using namespace std;

int isPrime(int n){
  if(n==1) return 0;
  for(int j=2;j*j<=n;j++){
    if(n%j == 0){
      return 0;
    }
  }

  return 1;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int num, count = 0;
  cin >> num;

  for(int i=0;i<num;i++){
    int n;
    cin >> n;
    count += isPrime(n);
  }
  cout << count;

  return 0;
}
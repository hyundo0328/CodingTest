#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

void isPrime(int n){
  if(n==1) return;

  for(int i=2; i*i<=n; i++){
    if(n%i == 0){
      return;
    }
  }

  prime.push_back(n);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i=1; i<=n; i++){
    isPrime(i);
  }

  int en = 0;
  int count = 0;
  int sum = 0;
  for(int st=0; st<prime.size(); st++){
    while(en < prime.size() && sum < n){
      if(en != prime.size()) sum += prime[en];
      en++;
    }

    if(en == n) break;
    if(sum == n) count++;
    sum -= prime[st];
  }

  cout << count;
}
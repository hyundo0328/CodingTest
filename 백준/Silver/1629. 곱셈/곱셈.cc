#include <bits/stdc++.h>
using namespace std;

long long multiple(int a, int b, int c){
  if(b == 1) return a % c;

  long long val = multiple(a, b/2, c);
  val = val * val % c;

  if(b % 2 == 0) return val;
  else return val * a % c;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long a, b, c;
  cin >> a >> b >> c;

  cout << multiple(a,b,c);
}
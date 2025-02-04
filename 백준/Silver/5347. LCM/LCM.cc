#include <bits/stdc++.h>
using namespace std;

long long gcd(int a, int b){
  while(b != 0){
		int r = a % b;
		a = b;
		b = r;
	}
  
	return a;
}

long long lcm(int a, int b){
  return a * (b / gcd(a, b));
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  while(n-- > 0){
    int a, b;
    cin >> a >> b;

    if(a < b){
      int tmp = a;
      a = b;
      b = tmp;
    }

    cout << lcm(a, b) << '\n';
  }
}
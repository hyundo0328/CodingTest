#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  while(b != 0){
		int r = a % b;
		a = b;
		b = r;
	}
  
	return a;
}

int a[102];
long long sum;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while(t-- > 0){
    int n;
    cin >> n;

    sum = 0;
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    sort(a, a+n, greater<int>());

    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        sum += gcd(a[i],a[j]);
      }
    }

    cout << sum << '\n';
  }
}
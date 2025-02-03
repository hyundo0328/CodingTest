#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int count = 0;
  while(n != 0)
  {
    if (n % 125 == 0)
        count += 3;
    else if (n % 25 == 0)
        count += 2;
    else if (n % 5 == 0)
        count++;
    n--;
  }
  cout << count;
}
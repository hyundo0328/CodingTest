#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  while(n > 0){
    int num = n%10;
    
    if(num == 6 || num == 9){
      if(cnt[6] >= cnt[9]) cnt[9]++;
      else cnt[6]++;
    } else {
      cnt[num]++;
    }

    n /= 10;
  }

  cout << *max_element(cnt, cnt+10);
}
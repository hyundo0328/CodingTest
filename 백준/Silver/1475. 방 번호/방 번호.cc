#include <iostream> 
// #include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int count = 0;
  int num[10] = {0,};

  while(n > 0){
    num[n%10]++;
    n = n/10;
  }

  for(int i=0;i<10;i++){
    if(i==6 || i==9){
      continue;
    }
    count = max(count,num[i]);
  }

  count = max(count, (num[6]+num[9]+1)/2);
  cout << count;
  
  return 0;
}
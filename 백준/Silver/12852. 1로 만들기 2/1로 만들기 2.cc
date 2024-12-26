#include <bits/stdc++.h>
using namespace std;

int d[1000005];
int pre[1000005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num;
  cin >> num;
  d[1] = 0; pre[1] = 0;
  d[2] = 1; pre[2] = 1;
  d[3] = 1; pre[3] = 1;

  for(int i=4;i<=num;i++){
    d[i] = d[i-1]+1;
    pre[i] = i-1;

    if(i%2 == 0 && d[i] > d[i/2]+1){
      d[i] = d[i/2] + 1;
      pre[i] = i/2;
    }
    if(i%3 == 0 && d[i] > d[i/3]+1){
      d[i] = d[i/3] + 1;
      pre[i] = i/3;
    }
  }

  cout << d[num] << '\n';
  int cur = num;

  while(cur != 1){
    cout << cur << ' ';
    cur = pre[cur];    
  }
  cout << 1;
}
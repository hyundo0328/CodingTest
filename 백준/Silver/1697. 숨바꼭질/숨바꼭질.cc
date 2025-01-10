#include <bits/stdc++.h>
using namespace std;

int dis[200002];
int n, k;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(dis, dis+200001,-1);

  cin >> n >> k;
  dis[n] = 0;
  queue<int> Q;
  Q.push(n);

  while(dis[k] == -1){
    auto cur = Q.front();
    Q.pop();

    for(int move : {cur-1, cur+1, 2*cur}){
      if(dis[move] != -1) continue;
      if(move < 0 || move > 100000) continue;
      dis[move] = dis[cur] + 1;
      Q.push(move);
    }  
  }

  cout << dis[k];
}
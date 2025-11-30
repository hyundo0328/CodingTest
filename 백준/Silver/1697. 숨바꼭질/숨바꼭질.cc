#include <bits/stdc++.h>
using namespace std;

int dis[200004];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  fill(dis, dis+200003, -1);

  queue<int> q;
  q.push(n);
  dis[n] = 0;

  while(!q.empty()){
    int cur = q.front(); q.pop();

    for(int nx:{cur+1, cur-1, 2*cur}){
      if(nx < 0 || nx > 100000) continue;
      if(dis[nx] != -1) continue;

      dis[nx] = dis[cur] + 1;
      q.push(nx);
    }
  }

  cout << dis[k];
}
#include <bits/stdc++.h>
using namespace std;

int n, m, mx;
vector<int> adj[20002];
int dist[20002];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  memset(dist, -1, sizeof(dist));
  queue<int> q;
  q.push(1);
  dist[1] = 0;

  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(auto nxt:adj[cur]){
      if(dist[nxt] > -1) continue;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
      mx = max(mx, dist[nxt]);
    }
  }

  int count = 0;
  for(int i = 1; i <= n; i++) {
    if(dist[i] == mx) {
      if(!count) cout << i << ' ';
      count++;
    }
  }
  cout << mx << ' ' << count;
}
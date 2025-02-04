#include <bits/stdc++.h>
using namespace std;

int n, m, v;
vector<int> adj[1002];
bool vis[1002];

void dfs(int cur){
  vis[cur] = true;
  cout << cur << ' ';

  for(auto nxt: adj[cur]){
    if(vis[nxt]) continue;
    dfs(nxt);
  }
}

void bfs(int n){
  queue<int> q;
  q.push(n);
  vis[n] = true;

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    cout << cur << ' ';

    for(auto nxt : adj[cur]){
      if(vis[nxt]) continue;

      vis[nxt] = true;
      q.push(nxt);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> v;
  int a, b;
  for(int i=0;i<m;i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 1; i <= n; i++){
    sort(adj[i].begin(), adj[i].end());
  }

  dfs(v);

  cout << '\n';
  fill(vis, vis+n+1, false);
  
  bfs(v);
}
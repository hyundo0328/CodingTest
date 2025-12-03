#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1002];
bool vis[1002];

void dfs(int cur){
  vis[cur] = true;
  cout << cur << " ";
  for(int nxt:adj[cur]){
    if(vis[nxt]) continue;

    dfs(nxt);
  }
}

void bfs(int num){
  queue<int> q;
  q.push(num);
  vis[num] = true;
  
  while(!q.empty()){
    int cur = q.front(); q.pop();

    cout << cur << " ";
    for(int nxt:adj[cur]){
      if(vis[nxt]) continue;

      vis[nxt] = true;
      q.push(nxt);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, v;
  cin >> n >> m >> v;

  while(m--){
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  for(int i=1; i<=n; i++) sort(adj[i].begin(), adj[i].end());

  dfs(v);
  cout << '\n';

  fill(vis, vis+1002, false);
  bfs(v);
}
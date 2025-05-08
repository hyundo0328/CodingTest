#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1002];
bool vis[1002];

void bfs(int n){
  queue<int> Q;
  Q.push(n);

  while(!Q.empty()){
    int cur = Q.front(); Q.pop();

    for(int nxt:adj[cur]){
      if(vis[nxt]) continue;

      Q.push(nxt);
      vis[nxt] = true;
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  while(m-- > 0){
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int count = 0;
  for(int i=1; i<=n; i++){
    if(vis[i]) continue;
    vis[i] = true;
    count++;
    bfs(i);
  }

  cout << count;
}
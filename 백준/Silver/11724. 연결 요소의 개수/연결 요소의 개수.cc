#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1002];
bool vis[1002];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  while(m--){
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  queue<int> q;
  int cnt = 0;
  for(int i=1; i<=n; i++){
    if(vis[i]) continue;

    cnt++;
    q.push(i);
    while(!q.empty()){
      int cur = q.front(); q.pop();

      for(int nxt:adj[cur]){
        if(vis[nxt]) continue;

        vis[nxt] = true;
        q.push(nxt);
      }
    }
  }

  cout << cnt;
}
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1000001];
bool vis[1000001];
bool isTree;

void dfs(int cur, int prev){
  for(auto nxt:adj[cur]){
    if(nxt == prev) continue; // nxt이 부모와 동일할 경우
    if(vis[nxt]){ // 부모가 아닌데 방문한 경우 -> 싸이클
      isTree = false;
      continue;
    }

    vis[nxt] = true;
    dfs(nxt, cur);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num = 1;
  while(true){
    cin >> n >> m;

    if(n == 0 && m == 0) break;

    for(int i=0;i<m;i++){
      int u, v;
      cin >> u >> v;

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int trees = 0;
    for(int i=1; i<=n; i++){
      if(vis[i]) continue;

      vis[i] = true;
      isTree = true;

      dfs(i, -1);
      trees += isTree;
    }

    if (!trees)
      cout << "Case " << num << ": No trees." << '\n';
    else if (trees == 1)
      cout << "Case " << num << ": There is one tree." << '\n';
    else
      cout << "Case " << num << ": A forest of " << trees << " trees." << '\n';

    for(int i=1; i<=n; i++) adj[i].clear(); // 초기화
    fill(vis, vis+1000001, false);
    num++;
  }

}
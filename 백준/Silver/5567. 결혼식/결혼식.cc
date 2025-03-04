#include <bits/stdc++.h>
using namespace std;

vector<int> adj[502];
int vis[502];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int person;
  int t;

  cin >> person;
  cin >> t;

  while(t-- > 0){
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vis[1] = 1;
  queue<int> q;
  q.push(1);

  int num = 0;
  while(!q.empty()){
    int cur = q.front(); q.pop();

    if(vis[cur] > 2) continue;

    for(auto nxt : adj[cur]){
      if(vis[nxt] > 0) continue;

      vis[nxt] = vis[cur] + 1;
      q.push(nxt);
      num++;
    }
  }

  cout << num;
}
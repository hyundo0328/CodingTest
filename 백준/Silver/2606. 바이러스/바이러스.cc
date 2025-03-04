#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool vis[1005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  int com, t;

  cin >> com;
  cin >> t;

  while(t-- > 0){
    int c1, c2;
    cin >> c1 >> c2;

    adj[c1].push_back(c2);
    adj[c2].push_back(c1);
  }

  int num = 0;
  queue<int> q;
  q.push(1);
    
  vis[1] = true;
  while(!q.empty()){
    int cur = q.front(); q.pop();
      
    for(auto nxt : adj[cur]){
      if(vis[nxt]) continue;
      q.push(nxt);
      vis[nxt] = true;
      num++;
    }
  }
    
  cout << num;
}
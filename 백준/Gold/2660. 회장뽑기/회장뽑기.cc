#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[52];
int score[52];

int bfs(int st){
  queue<int> q;
  q.push(st);

  int dis[52];
  fill(dis+1, dis+n+1, -1);
  dis[st] = 0;

  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(auto nxt : adj[cur]){
      if(dis[nxt] != -1) continue;

      dis[nxt] = dis[cur] + 1;
      q.push(nxt);
    }
  }

  int val = *max_element(dis+1, dis+n+1);

  if(val == 0) {
    return 52;
  } else {
    return val;
  }

}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  while(1){
    int a, b;
    cin >> a >> b;

    if(a == -1 && b == -1){
      break;
    } else {
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }

  for(int i=1;i<=n;i++){
    score[i] = bfs(i);
  }
  
  int minScore = *min_element(score+1, score+n+1);
  vector<int> candidate;
  for(int i = 1; i <= n; i++){
    if(score[i] == minScore){
      candidate.push_back(i);
    }
  }

  cout << minScore << ' ' << candidate.size() << '\n';
  for(int cand : candidate) {
    cout << cand << ' ';
  }
}
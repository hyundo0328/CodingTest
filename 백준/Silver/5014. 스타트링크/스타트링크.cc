#include <bits/stdc++.h>
using namespace std;

int building[1000002];
long long times[1000002];
int f, s, g, u, d;
vector<int> vec;
queue<int> q;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  // f: 건물 층수
  // s: 현재 층수
  // g: 목표 층수
  // u: 올라가는 층수
  // d: 내려가는 층수
  cin >> f >> s >> g >> u >> d;
  q.push(s);
  vec.push_back(u);
  vec.push_back(-d);
  memset(times, -1, sizeof(times));
  times[s] = 0;

  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(int dir:vec){
      int nxt = cur + dir;
        
      if(nxt < 1 || nxt > f) continue;
      if(times[nxt] != -1) continue;

      times[nxt] = times[cur] + 1;
      q.push(nxt);
    }
  }

  if(times[g] == -1) cout << "use the stairs";
  else cout << times[g];
}
#include <bits/stdc++.h>
using namespace std;

int n, k;
int dis[100001];
queue<int> q;

void teleport(int num){
  int tmp = num;

  if (!tmp) return; // 시작 위치가 0일 경우
  while(tmp <= 100000){
    if(dis[tmp] == -1){
      dis[tmp] = dis[num];
      q.push(tmp);

      if(tmp == k) return;
    }

    tmp *= 2;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  fill(dis, dis + 100001, -1);
  dis[n] = 0;
  q.push(n);

  teleport(n);

  while(!q.empty()){
    int cur = q.front(); q.pop();

    for(int nxt:{cur-1, cur+1}){
      if(nxt < 0 || nxt > 100000) continue;
      if(dis[nxt] != -1) continue;

      dis[nxt] = dis[cur] + 1;
      q.push(nxt);

      teleport(nxt);
    }
  }

  cout << dis[k];
}
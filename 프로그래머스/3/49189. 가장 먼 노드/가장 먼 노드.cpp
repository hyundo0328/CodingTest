#include <bits/stdc++.h>

using namespace std;

vector<int> adj[20002];
int dist[20002];

int solution(int n, vector<vector<int>> edge) {  
    for(auto arr:edge){
        int u = arr[0], v = arr[1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    memset(dist, -1, sizeof(dist));
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    int answer = 0, max = 0;
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        
        for(auto nxt:adj[cur]){
            if(dist[nxt] > -1) continue;
            
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
            
            if(max < dist[nxt]){
                cout << "dist[nxt]: " << dist[nxt] << '\n';
                max = dist[nxt];
                answer = 0;
            } else {
                cout << "nxt: " << nxt << '\n';
                answer++;
            }
        }
    }    
    
    return answer+1;
}
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > maps){
    int ans = 0;
    int n = maps[0].size();
    int m = maps.size();
    
    int dis[104][104];

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    memset(dis, -1, sizeof(dis));
    
    queue<pair<int,int>> Q;
    Q.push({0,0});
    dis[0][0] = 1;
    
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int k=0;k<4;k++){
            int nx = cur.second + dx[k];
            int ny = cur.first + dy[k];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(maps[ny][nx] == 0) continue;
            if(dis[ny][nx] >= 0) continue;
            
            dis[ny][nx] = dis[cur.first][cur.second] + 1;
            Q.push({ny,nx});
        }
    }
    
    if(dis[m-1][n-1] == -1){
        ans = -1;
    } else {
        ans = dis[m-1][n-1];
    }
    return ans;
}
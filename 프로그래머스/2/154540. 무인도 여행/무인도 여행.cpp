#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int visited[102][102];

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int n = maps.size();
    int m = maps[0].size();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maps[i][j] != 'X' && visited[i][j] == 0) {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;
                int sum = (maps[i][j]-'0');
                
                while(!q.empty()) {
                    auto cur = q.front(); q.pop();
                    
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(maps[nx][ny] == 'X' || visited[nx][ny] == 1) continue;
                        q.push({nx, ny});
                        visited[nx][ny] = 1;
                        sum += (maps[nx][ny] - '0');
                    }
                }
                 answer.push_back(sum);
            }
        }
    }
    if(answer.size() == 0){
        answer.push_back(-1);
    } else {
        sort(answer.begin(), answer.end());    
    }
        
    return answer;
}
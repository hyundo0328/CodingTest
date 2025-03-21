#include <bits/stdc++.h>
using namespace std;

bool fight[102][102];
const int MAX = 0x3f3f3f3f;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(auto arr:results){
        int a = arr[0], b = arr[1];
        fight[a][b] = true;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(fight[i][k] && fight[k][j]){
                    fight[i][j] = true;
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        int cnt =0; 
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            if(fight[i][j] || fight[j][i]) cnt++; 
        }
        if(cnt == n-1) answer++; 
    } 
    
    return answer;
}
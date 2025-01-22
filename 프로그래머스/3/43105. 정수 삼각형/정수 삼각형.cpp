#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> triangle) {    
    int arr[501][501];
    arr[0][0] = triangle[0][0];
    arr[1][0] = arr[0][0] + triangle[1][0];
    arr[1][1] = arr[0][0] + triangle[1][1];
    for(int i=2;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            if(j==0) arr[i][j] = arr[i-1][j] + triangle[i][j];
            if(j==triangle[i].size()-1) arr[i][j] = arr[i-1][j-1] + triangle[i][j];
            
            int tmp = max(arr[i-1][j-1], arr[i-1][j]);
            arr[i][j] = tmp+triangle[i][j];
        }
    }
    
    int ans = 0;
    for(auto n:arr[triangle.size()-1]){
        ans = max(ans, n);
    }
    
    return ans;
}
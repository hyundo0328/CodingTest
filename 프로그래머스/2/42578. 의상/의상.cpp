#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> m;
    for(auto kind:clothes){
        m[kind[1]]++;
    }
    
    for(auto p:m){
        answer*=(p.second+1);
    }
    
    return answer-1;
}
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto scovil:scoville){
        pq.push(scovil);
    }
    
    while(pq.size() >= 2 && pq.top() < K){
        int min = pq.top(); pq.pop();
        int min2 = pq.top(); pq.pop();
        int sum = min + 2*min2;
        
        answer++;
        pq.push(sum);
    }
    
    if (!pq.empty() && pq.top() < K) {
        return -1;
    } else {
        return answer;   
    }
}
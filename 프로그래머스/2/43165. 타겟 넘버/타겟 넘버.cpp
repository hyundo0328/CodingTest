#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    queue<int> q;
    q.push(numbers[0]);
    q.push(-1*numbers[0]);
    
    for(int i=1;i<numbers.size();i++){
        int qsize = q.size();
        for(int k=0; k<qsize; k++){
            auto sum = q.front(); q.pop();
            q.push(sum+numbers[i]);
            q.push(sum-numbers[i]);
        }
    }
    
    int qsize = q.size();
    for(int i=0;i<qsize;i++){
        if(q.front() == target) answer++;
        q.pop();
    }
    
    return answer;
}